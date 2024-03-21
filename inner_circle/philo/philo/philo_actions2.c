/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:26:40 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 21:25:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork_status(t_common *common, int fork_num)
{
	int	status;

	pthread_mutex_lock(&common->fork_status_mutex[fork_num]);
	status = common->fork_status[fork_num];
	pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
	return (status);
}

void	update_last_time_eat(t_common *common, t_philo *philo)
{
	philo->last_eat_time = get_cur_time_us();
	printf_philo(common, philo->num_philo, "is eating");
	if (common->num_must_eat != -1)
		philo->num_eat++;
}

void	release_fork(t_common *common, int fork_num)
{
	pthread_mutex_lock(&common->fork_status_mutex[fork_num]);
	common->fork_status[fork_num] -= FORK_BUSY;
	common->fork_status[fork_num]++;
	common->fork_status[fork_num] %= 2;
	pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
}

int	increase_philo_at_barrier(t_common *common)
{
	while (is_finished(common) == FALSE)
	{
		pthread_mutex_lock(&common->barrier_flag_mutex);
		if (common->barrier_flag == FALSE)
		{
			pthread_mutex_lock(&common->philo_at_barrier_mutex);
			common->philo_at_barrier++;
			// printf("philo_at_barrier increase [%d]\n", common->philo_at_barrier);
			pthread_mutex_lock(&common->finished_philo_mutex);
			if (common->philo_at_barrier
				== (common->num_of_philo - common->finished_philo) / 2)
				common->barrier_flag = TRUE;
			pthread_mutex_unlock(&common->finished_philo_mutex);
			pthread_mutex_unlock(&common->philo_at_barrier_mutex);
			pthread_mutex_unlock(&common->barrier_flag_mutex);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&common->barrier_flag_mutex);
		sleep(100);
	}
	return (FAIL);
}

int	decrease_philo_at_barrier(t_common *common)
{
	// printf("decrease\n");
	pthread_mutex_lock(&common->philo_at_barrier_mutex);
	common->philo_at_barrier--;
	// printf("philo_at_barrier [%d]\n", common->philo_at_barrier);
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
		// printf("philo_num : [%d]\n", philo->num_philo);
		if (common->barrier_flag == TRUE)
		{
			decrease_philo_at_barrier(common);
			pthread_mutex_unlock(&common->barrier_flag_mutex);
			return (SUCCESS);
		}
		pthread_mutex_unlock(&common->barrier_flag_mutex);
		usleep(100);
	}
	return (FAIL);
}

