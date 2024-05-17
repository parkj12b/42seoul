/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barrier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:59:56 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 15:19:52 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	increase_philo_at_barrier(t_common *common)
{
	while (is_finished(common) == FALSE)
	{
		pthread_mutex_lock(&common->barrier_flag_mutex);
		if (common->barrier_flag == FALSE)
		{
			pthread_mutex_lock(&common->philo_at_barrier_mutex);
			common->philo_at_barrier++;
			pthread_mutex_lock(&common->finished_philo_mutex);
			if (common->philo_at_barrier
				== (common->num_of_philo / 2)
				|| (common->philo_at_barrier
					== common->num_of_philo - common->finished_philo))
				common->barrier_flag = TRUE;
			pthread_mutex_unlock(&common->finished_philo_mutex);
			pthread_mutex_unlock(&common->philo_at_barrier_mutex);
			pthread_mutex_unlock(&common->barrier_flag_mutex);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&common->barrier_flag_mutex);
		usleep(common->num_of_philo);
	}
	return (FAIL);
}

static int	decrease_philo_at_barrier(t_common *common)
{
	pthread_mutex_lock(&common->philo_at_barrier_mutex);
	common->philo_at_barrier--;
	if (common->philo_at_barrier == 0)
		common->barrier_flag = FALSE;
	pthread_mutex_unlock(&common->philo_at_barrier_mutex);
	return (SUCCESS);
}

int	wait_at_barrier(t_common *common, t_philo *philo)
{
	(void) philo;
	if (increase_philo_at_barrier(common) == FAIL)
		return (FAIL);
	while (is_finished(common) == FALSE)
	{
		pthread_mutex_lock(&common->barrier_flag_mutex);
		if (common->barrier_flag == TRUE)
		{
			decrease_philo_at_barrier(common);
			pthread_mutex_unlock(&common->barrier_flag_mutex);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&common->barrier_flag_mutex);
		usleep(common->num_of_philo);
	}
	return (FAIL);
}
