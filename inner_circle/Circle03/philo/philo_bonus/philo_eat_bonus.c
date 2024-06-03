/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:17:47 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 13:18:09 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	update_last_time_eat(t_common *common, t_philo *philo)
{
	sem_wait(philo->last_time_lock);
	sem_wait(common->print_lock);
	philo->last_eat_time = get_cur_time_us();
	printf_philo(common, philo->philo_num, "has taken a fork", FALSE);
	printf_philo(common, philo->philo_num, "has taken a fork", FALSE);
	printf_philo(common, philo->philo_num, "is eating", FALSE);
	sem_post(common->print_lock);
	sem_post(philo->last_time_lock);
}

void	take_fork(t_common *common, t_philo *philo)
{
	(void) philo;
	sem_wait(common->fork);
	sem_wait(common->fork);
}

static void	release_fork(t_common *common)
{
	sem_post(common->fork);
	sem_post(common->fork);
}

void	start_eat_routine(t_common *common, t_philo *philo)
{
	sem_wait(philo->fork_lock);
	update_last_time_eat(common, philo);
	ft_msleep(common->time_to_eat);
	release_fork(common);
	sem_wait(philo->num_eat_lock);
	philo->num_eat++;
	sem_post(philo->num_eat_lock);
}
