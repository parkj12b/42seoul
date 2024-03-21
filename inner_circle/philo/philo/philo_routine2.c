/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:16:57 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 16:20:42 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_in_action(size_t start_time, size_t duration_ms)
{
	size_t	time_diff;

	time_diff = get_cur_time_us() - start_time;
	if (time_diff >= duration_ms * 1000)
		return (FALSE);
	return (TRUE);
}

int	start_sleep_routine(t_common *common, t_philo *philo)
{
	size_t	start_time;

	start_time = get_cur_time_us();
	printf_philo(common, philo->num_philo, "is sleeping");
	while (is_in_action(start_time, common->time_to_sleep))
	{
		if (is_finished(common) == TRUE || is_dead(common, philo) == TRUE)
		{
			return (FAIL);
		}
		if (common->time_to_sleep - (get_cur_time_us() - start_time) > 1000000)
			usleep(500);
		else
			usleep(0);
	}
	return (SUCCESS);
}
