/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:26:40 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 16:52:44 by minsepar         ###   ########.fr       */
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

void	set_fork_busy(t_common *common, int fork_num)
{
	pthread_mutex_lock(&common->fork_status_mutex[fork_num]);
	common->fork_status[fork_num] += FORK_BUSY;
	pthread_mutex_unlock(&common->fork_status_mutex[fork_num]);
}
