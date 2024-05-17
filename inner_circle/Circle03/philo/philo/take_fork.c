/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:44:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 15:20:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_take_fork(t_common *common, t_philo *philo, int fork_num)
{
	if (philo->left_fork == fork_num && common->fork_status[fork_num] % 2 == 0)
	{
		common->fork_status[fork_num] += FORK_BUSY;
		return (SUCCESS);
	}
	else if (philo->right_fork == fork_num
		&& common->fork_status[fork_num] % 2 == 1)
	{
		common->fork_status[fork_num] += FORK_BUSY;
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
		printf_philo(common, philo->num_philo, "has taken a fork");
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
		usleep(common->num_of_philo);
	}
	return (FAIL);
}
