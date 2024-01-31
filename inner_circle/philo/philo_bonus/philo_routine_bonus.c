/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:30:16 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/31 21:09:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_child(t_args *t_args, t_philo **philo)
{
	int		i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		t_args->child_pid[i] = fork();
		if (t_args->child_pid[i] < 0)
			kill(-1, SIGKILL);
		if (t_args->child_pid[i] == 0)
			break ;
	}
	if (i < t_args->num_philo && t_args->child_pid[i] == 0)
	{
		sem_wait(t_args->process_lock);
		philo_routine(philo[i], t_args);
	}
	if (t_args->child_pid[0] != 0)
	{
		i = -1;
		while (++i < t_args->num_philo)
			sem_post(t_args->process_lock);
		parent_wait(t_args);
	}
}

void	philo_routine(t_philo *philo, t_args *t_args)
{
	gettimeofday(&philo->time_last_meal, NULL);
	pthread_create(&(philo->thread), NULL, check_dead, philo);
	if (t_args->num_philo == 1)
		printf_philo(philo->philo_num, "has taken a fork", t_args);
	while (t_args->num_philo > 1)
	{
		philo_eat(philo, t_args);
		if (t_args->num_must_eat >= 0
			&& philo->meal_count == t_args->num_must_eat)
			exit(0);
		philo_sleep(philo, t_args);
		printf_philo(philo->philo_num, "is thinking", t_args);
	}
	pthread_join(philo->thread, NULL);
}

void	*check_dead(void *arg)
{
	struct timeval	now;
	t_args			*t_args;
	t_philo			*philo;
	long long		diff;

	philo = (t_philo *) arg;
	t_args = philo->arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		sem_wait(philo->last_meal_lock);
		diff = (now.tv_sec - philo->time_last_meal.tv_sec) * 1000000
			+ (now.tv_usec - philo->time_last_meal.tv_usec);
		sem_post(philo->last_meal_lock);
		sem_wait(t_args->finish_lock);
		if (diff >= t_args->time_to_die * 1000)
		{
			printf_dead(philo->philo_num, t_args);
			exit(1);
		}
		sem_post(t_args->finish_lock);
		usleep(100);
	}
	return (0);
}
