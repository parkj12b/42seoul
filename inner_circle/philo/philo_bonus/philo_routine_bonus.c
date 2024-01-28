/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:30:16 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/22 22:27:32 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_child(t_args *t_args, t_philo **philo)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < t_args->num_philo)
	{
		if (pid != 0)
			pid = fork();
		if (pid == 0)
			philo_routine(philo[i], t_args);
	}
	if (pid != 0)
		parent_wait(t_args);
}

void	philo_routine(t_philo *philo, t_args *t_args)
{
	start_monitor(philo, t_args);
	printf_philo(philo->philo_num, "is thinking", t_args);
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

void	start_monitor(t_philo *philo, t_args *t_args)
{
	if (pthread_create(&philo->thread, NULL, monitor, philo))
		throw_error("pthread_create() error");
}

void	*monitor(void *arg)
{
	struct timeval	now;
	t_philo			*philo;
	t_args			*t_args;
	long long		diff;

	philo = (t_philo *) arg;
	t_args = philo->arg;
	while (1)
	{
		gettimeofday(&now, NULL);
		diff = (now.tv_sec - philo->time_last_meal.tv_sec) * 1000000
			+ (now.tv_usec - philo->time_last_meal.tv_usec);
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
