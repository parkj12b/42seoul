/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:57:08 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 16:03:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_common *common, t_philo *philo)
{
	size_t	time_diff;
	size_t	time_to_die_usec;

	sem_wait(philo->last_time_lock);
	time_diff = get_cur_time_us() - philo->last_eat_time;
	time_to_die_usec = common->time_to_die * 1000;
	if (time_diff >= time_to_die_usec)
	{
		sem_wait(common->print_lock);
		printf("%zu %d died\n", get_timestamp_ms(common), philo->philo_num);
		sem_post(philo->last_time_lock);
		return (TRUE);
	}
	sem_post(philo->last_time_lock);
	return (FALSE);
}

void	ft_msleep(int msec)
{
	size_t	start;
	size_t	cur;
	size_t	duration_usec;

	start = get_cur_time_us();
	cur = start;
	duration_usec = msec * 1000;
	while (cur - start < duration_usec)
	{
		cur = get_cur_time_us();
		if (duration_usec - (cur - start) > 1000)
		{
			usleep(500);
		}
	}
}
