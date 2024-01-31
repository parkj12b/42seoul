/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:55:42 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/29 21:17:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_t_args(t_args *t_args, int argc, char **argv)
{
	gettimeofday(&(t_args->start_time), NULL);
	t_args->num_philo = ft_atoi(argv[1]);
	t_args->time_to_die = ft_atoi(argv[2]);
	t_args->time_to_eat = ft_atoi(argv[3]);
	t_args->time_to_sleep = ft_atoi(argv[4]);
	t_args->finished_philo = 0;
	t_args->finish_flag = 0;
	t_args->num_must_eat = -1;
	t_args->startup_count = 0;
	if (argc == 6)
		t_args->num_must_eat = ft_atoi(argv[5]);
	if (t_args->num_philo <= 0 || t_args->time_to_die < 0
		|| t_args->time_to_eat < 0 || t_args->time_to_sleep < 0
		|| (argc == 6 && t_args->num_must_eat < 0))
		return (ERROR);
	if (init_mutex(t_args) == ERROR)
		return (ERROR);
	return (0);
}

int	init_mutex(t_args *t_args)
{
	int	i;

	t_args->fork = malloc(sizeof(pthread_mutex_t) * t_args->num_philo);
	if (!t_args->fork)
		return (ERROR);
	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_init(&t_args->fork[i], NULL);
	}
	pthread_mutex_init(&t_args->print_mutex, NULL);
	pthread_mutex_init(&t_args->finish_mutex, NULL);
	pthread_mutex_init(&t_args->limit_count_mutex, NULL);
	return (0);
}

t_philo	**init_philo(t_args *t_args)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * t_args->num_philo);
	if (!philo)
		return (0);
	i = -1;
	while (++i < t_args->num_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->philo_num = i + 1;
		philo[i]->left_fork = i;
		philo[i]->right_fork = i + 1;
		philo[i]->meal_count = 0;
		philo[i]->arg = t_args;
		pthread_mutex_init(&philo[i]->last_meal_mutex, NULL);
		pthread_mutex_init(&philo[i]->meal_count_mutex, NULL);
		gettimeofday(&(philo[i]->time_last_meal), NULL);
	}
	philo[i - 1]->right_fork = 0;
	return (philo);
}
