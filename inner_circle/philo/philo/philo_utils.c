/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:29 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 23:34:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_common *common, t_philo *philo)
{
	size_t			time_diff;
	size_t			time_to_die_usec;

	time_diff = get_cur_time_us() - philo->last_eat_time;
	time_to_die_usec = common->time_to_die * 1000;
	if (time_diff >= time_to_die_usec)
	{
		pthread_mutex_lock(&common->finish_flag_mutex);
		if (common->finish_flag == TRUE)
		{
			pthread_mutex_unlock(&common->finish_flag_mutex);
			return (TRUE);
		}
		common->finish_flag = TRUE;
		printf("%zu %d died\n", get_timestamp_ms(common), philo->num_philo);
		pthread_mutex_unlock(&common->finish_flag_mutex);
		return (TRUE);
	}
	return (FALSE);
}

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

int	is_in_action(size_t start_time, size_t duration_ms)
{
	size_t	time_diff;

	time_diff = get_cur_time_us() - start_time;
	if (time_diff >= duration_ms * 1000)
		return (FALSE);
	return (TRUE);
}
