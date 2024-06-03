/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 15:36:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eating_in_action(t_common *common,
	t_philo *philo, size_t start_time)
{
	while (is_in_action(start_time, common->time_to_eat))
	{
		if (is_finished(common) == TRUE || is_dead(common, philo))
		{
			return (FAIL);
		}
		if (common->time_to_eat - (get_cur_time_us() - start_time) > 1000000)
		{
			usleep(500);
		}
	}
	return (SUCCESS);
}

static void	release_fork(t_common *common, int fork_num)
{
	pthread_mutex_lock(&common->fork_status_mutex[fork_num]);
	common->fork_status[fork_num] -= FORK_BUSY;
	common->fork_status[fork_num]++;
	common->fork_status[fork_num] %= 2;
	pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
}

static void	update_last_time_eat(t_common *common, t_philo *philo)
{
	philo->last_eat_time = get_cur_time_us();
	printf_philo(common, philo->num_philo, "is eating");
	if (common->num_must_eat != -1)
		philo->num_eat++;
	if (common->num_must_eat == philo->num_eat)
	{
		pthread_mutex_lock(&common->finished_philo_mutex);
		common->finished_philo++;
		pthread_mutex_unlock(&common->finished_philo_mutex);
	}
}

int	start_eat_routine(t_common *common, t_philo *philo)
{
	size_t	start_time;
	int		status;

	status = 0;
	if (take_fork(common, philo, philo->left_fork) != SUCCESS
		|| take_fork(common, philo, philo->right_fork) != SUCCESS)
		return (FAIL);
	if (wait_at_barrier(common, philo) == FAIL)
	{
		release_fork(common, philo->left_fork);
		release_fork(common, philo->right_fork);
		return (FAIL);
	}
	update_last_time_eat(common, philo);
	start_time = get_cur_time_us();
	status = eating_in_action(common, philo, start_time);
	release_fork(common, philo->left_fork);
	release_fork(common, philo->right_fork);
	return (status);
}
