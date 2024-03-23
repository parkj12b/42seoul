/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:17:47 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 15:40:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	update_last_time_eat(t_common *common, t_philo *philo)
{
	// printf("update_last_time [%s]\n", philo->last_time_lock_str);
	sem_wait(philo->last_time_lock);
	philo->last_eat_time = get_cur_time_us();
	// printf("update_last_time [%s]\n", philo->num_eat_lock_str);
	sem_wait(philo->num_eat_lock);
	philo->num_eat++;
	sem_post(philo->num_eat_lock);
	printf_philo(common, philo->philo_num, "is eating");
	sem_post(philo->last_time_lock);
}

static void	take_fork(t_common *common, t_philo *philo)
{
	sem_wait(common->fork_lock);
	sem_wait(common->fork);
	printf_philo(common, philo->philo_num, "has taken a fork");
	sem_wait(common->fork);
	printf_philo(common, philo->philo_num, "has taken a fork");
	sem_post(common->fork_lock);
}

static void	release_fork(t_common *common)
{
	sem_post(common->fork);
	sem_post(common->fork);
}

void	start_eat_routine(t_common *common, t_philo *philo)
{
	take_fork(common, philo);
	update_last_time_eat(common, philo);
	ft_msleep(common->time_to_eat);
	release_fork(common);
}
