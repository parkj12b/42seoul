/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:42 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/14 19:57:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork_status(t_args *t_args)
{
	int	i;

	t_args->fork_status = malloc(sizeof(int) * t_args->num_philo);
	if (!t_args->fork_status)
	{
		t_args->error_num = EFNFAIL;
		return (EFNFAIL);
	}
	memset(t_args->fork_status, 0, sizeof(sizeof(int) * t_args->num_philo));
	i = -1;
	while (++i < t_args->num_philo)
	{
		t_args->fork_status[i] = i % 2;
	}
	return (0);
}

int	init_t_args(t_args *args, int argc, char **argv)
{
	memset(args, 0, sizeof(t_args));
	gettimeofday(&(args->start_time), NULL);
	args->num_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->num_must_eat = -1;
	if (argc == 6)
		args->num_must_eat = ft_atoi(argv[5]);
	if (args->num_philo <= 0 || args->time_to_die < 0
		|| args->time_to_eat < 0 || args->time_to_sleep < 0
		|| (argc == 6 && args->num_must_eat < 0))
	{
		args->error_num = EARGVAL;
		return (EARGVAL);
	}
	if (init_mutex(args) != 0 || init_fork_status(args) != 0)
		return (args->error_num);
	return (0);
}

int	init_mutex(t_args *t_args)
{
	int	i;

	t_args->fork = malloc(sizeof(pthread_mutex_t) * t_args->num_philo);
	if (!t_args->fork)
	{
		t_args->error_num = EFNFAIL;
		return (EFNFAIL);
	}
	memset(t_args->fork, 0, sizeof(sizeof(pthread_mutex_t) * t_args->num_philo));
	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_init(&t_args->fork[i], NULL);
	}
	pthread_mutex_init(&t_args->print_mutex, NULL);
	pthread_mutex_init(&t_args->finish_mutex, NULL);
	pthread_mutex_init(&t_args->finish_count_mutex, NULL);
	pthread_mutex_init(&t_args->barrier_mutex, NULL);
	pthread_mutex_init(&t_args->num_philo_at_barrier_mutex, NULL);
	return (0);
}

t_philo	*init_philo(t_args *t_args, int index)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
	{
		t_args->error_num = EFNFAIL;
		return (NULL);
	}
	memset(philo, 0, sizeof(t_philo));
	philo->philo_num = index + 1;
	philo->left_fork = index;
	philo->right_fork = index + 1;
	philo->arg = t_args;
	if (index == t_args->num_philo - 1)
		philo->right_fork = 0;
	pthread_mutex_init(&philo->last_meal_mutex, NULL);
	pthread_mutex_init(&philo->meal_count_mutex, NULL);
	gettimeofday(&(philo->time_last_meal), NULL);
	return (philo);
}

t_philo	**init_philo_list(t_args *t_args)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * (t_args->num_philo + 1));
	if (!philo)
	{
		t_args->error_num = EFNFAIL;
		return (NULL);
	}
	memset(philo, 0, sizeof(t_philo *) * (t_args->num_philo + 1));
	i = -1;
	while (++i < t_args->num_philo)
	{
		philo[i] = init_philo(t_args, i);
		if (philo[i] == NULL)
		{
			free_philo_list(philo, t_args);
			return (NULL);
		}
	}
	return (philo);
}
