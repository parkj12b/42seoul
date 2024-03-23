/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:32:52 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 01:27:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	start_sleep_routine(t_common *common, t_philo *philo)
{
	printf_philo(common, philo->philo_num, "is sleeping");
	ft_msleep(common->time_to_sleep);
}

static void	*philo_routine(void *arg)
{
	t_philo		*philo;
	t_common	*common;

	philo = arg;
	common = philo->common;
	while (common->num_must_eat != philo->num_eat)
	{
		start_eat_routine(common, philo);
		sem_wait(philo->num_eat_lock);
		if (common->num_must_eat == philo->num_eat)
		{
			sem_post(philo->num_eat_lock);
			return (NULL);
		}
		sem_post(philo->num_eat_lock);
		start_sleep_routine(common, philo);
		printf_philo(common, philo->philo_num, "is thinking");
	}
	return (NULL);
}

static int	is_done_eating(t_common *common, t_philo *philo)
{
	sem_wait(philo->num_eat_lock);
	if (common->num_must_eat == philo->num_eat)
	{
		sem_post(philo->num_eat_lock);
		return (TRUE);
	}
	sem_post(philo->num_eat_lock);
	return (FALSE);
}

void	start_routine(t_common *common, t_philo *philo)
{
	pthread_create(&philo->routine_thread, NULL, philo_routine, (void *)philo);
	pthread_detach(philo->routine_thread);
	while (1)
	{
		if (is_dead(common, philo) == TRUE)
			exit(1);
		sem_wait(philo->last_time_lock);
		if (is_done_eating(common, philo) == TRUE)
		{
			sem_post(philo->last_time_lock);
			break ;
		}
		sem_post(philo->last_time_lock);
		usleep(500);
	}
	exit(0);
}
