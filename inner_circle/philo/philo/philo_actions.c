/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:56:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 21:29:39 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finished(t_common *common)
{
	pthread_mutex_lock(&common->finish_flag_mutex);
	if (common->finish_flag == TRUE)
	{
		pthread_mutex_unlock(&common->finish_flag_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&common->finish_flag_mutex);
	return (FALSE);
}

int	is_dead(t_common *common, t_philo *philo)
{
	size_t			time_diff;

	time_diff = get_cur_time_us() - philo->last_eat_time;
	if (time_diff >= (size_t) common->time_to_die * 1000)
	{
		set_finish_flag(common);
		print_philo_dead(common, philo);
		return (TRUE);
	}
	return (FALSE);
}

static int	try_take_fork(t_common *common, t_philo *philo, int fork_num)
{
	if (philo->left_fork == fork_num && common->fork_status[fork_num] % 2 == 0)
	{
		common->fork_status[fork_num] += FORK_BUSY;
		printf_philo(common, philo->num_philo, "has taken a fork");
		return (SUCCESS);
	}
	else if (philo->right_fork == fork_num && common->fork_status[fork_num] % 2 == 1)
	{
		common->fork_status[fork_num] += FORK_BUSY;
		printf_philo(common, philo->num_philo, "has taken a fork");
		return (SUCCESS);
	}
	return (FAIL);
}

static int	take_fork_helper(t_common *common, t_philo *philo, int fork_num)
{
	pthread_mutex_lock(&common->fork_status_mutex[fork_num]);
	if (common->fork_status[fork_num] > 1)
	{
		pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
		return (FAIL);
	}
	if (try_take_fork(common, philo, fork_num) == SUCCESS)
	{
		pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
		return (SUCCESS);
	}
	pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
	return (FAIL);
}

int	take_fork(t_common *common, t_philo *philo, int fork_num)
{
	while (is_finished(common) == FALSE)
	{
		if (take_fork_helper(common, philo, fork_num) == SUCCESS)
			return (SUCCESS);
		if (is_dead(common, philo))
			return (FAIL);
		usleep(100);
	}
	return (FAIL);
}

int	start_eat_routine(t_common *common, t_philo *philo)
{
	size_t	start_time;
	int		status;

	status = 0;
	if (take_fork(common, philo, philo->left_fork) != SUCCESS)
		return (FAIL);
	if (take_fork(common, philo, philo->right_fork) != SUCCESS)
		return (FAIL);
	if (wait_at_barrier(common, philo) == FAIL)
	{
		release_fork(common, philo->left_fork);
		release_fork(common, philo->right_fork);
		return (FAIL);
	}
	update_last_time_eat(common, philo);
	start_time = get_cur_time_us();
	while (is_in_action(start_time, common->time_to_eat))
	{
		if (is_finished(common) == TRUE || is_dead(common, philo))
		{
			status = FAIL;
			break ;
		}
		if (common->time_to_eat - (get_cur_time_us() - start_time) > 1000000)
			usleep(500);
		else
			usleep(0);
	}
	release_fork(common, philo->left_fork);
	release_fork(common, philo->right_fork);
	return (status);
}
