/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:29:01 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/31 21:51:43 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_t_args(t_args *t_args)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_print_lock");
	sem_unlink("sem_finish_lock");
	sem_unlink("process_lock");
	sem_unlink("half_control_lock");
	t_args->fork = sem_open("sem_fork", O_CREAT, 0644, t_args->num_philo);
	t_args->print_lock = sem_open("sem_print_lock", O_CREAT,
			0644, 1);
	t_args->half_control_lock = sem_open("half_control_lock", O_CREAT,
			0644, t_args->num_philo / 2);
	t_args->finish_lock = sem_open("sem_finish_lock", O_CREAT,
			0644, 1);
	t_args->process_lock = sem_open("process_lock", O_CREAT,
			0644, 0);
	t_args->child_pid = malloc(sizeof(int) * t_args->num_philo);
	if (!t_args->child_pid)
		throw_error("malloc failed");
}

void	parse_input(t_args *t_args, int argc, char **argv)
{
	gettimeofday(&t_args->start_time, NULL);
	t_args->num_philo = ft_atoi(argv[1]);
	t_args->time_to_die = ft_atoi(argv[2]);
	t_args->time_to_eat = ft_atoi(argv[3]);
	t_args->time_to_sleep = ft_atoi(argv[4]);
	t_args->num_must_eat = -1;
	if (argc == 6)
		t_args->num_must_eat = ft_atoi(argv[5]);
	if (t_args->num_philo <= 0 || t_args->time_to_die < 0
		|| t_args->time_to_eat < 0 || t_args->time_to_sleep < 0
		|| (argc == 6 && t_args->num_must_eat < 0))
		throw_error("invalid argument");
}

void	init_last_meal_lock(t_philo *philo)
{
	char	*philo_num;

	philo_num = ft_itoa(philo->philo_num);
	philo->last_meal_lock_str = ft_strcat("last_meal_lock_", philo_num);
	philo->last_meal_lock
		= sem_open(philo->last_meal_lock_str, O_CREAT, 0644, 1);
	free(philo_num);
}

t_philo	**init_philo(t_args *t_args)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * t_args->num_philo);
	if (!philo)
		throw_error("malloc failed");
	i = -1;
	while (++i < t_args->num_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		gettimeofday(&philo[i]->time_last_meal, NULL);
		if (!philo[i])
			throw_error("malloc failed");
		philo[i]->philo_num = i + 1;
		philo[i]->left_fork = i;
		philo[i]->right_fork = i + 1;
		philo[i]->meal_count = 0;
		philo[i]->arg = t_args;
		init_last_meal_lock(philo[i]);
	}
	philo[i - 1]->right_fork = 0;
	return (philo);
}
