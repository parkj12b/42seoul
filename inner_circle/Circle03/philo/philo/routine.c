/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:37:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 16:52:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_sleep_routine(t_common *common, t_philo *philo)
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
	}
	return (SUCCESS);
}

/**
 * philosopher thread's action, eat, sleep, think
*/
static void	*philo_routine(void *arg)
{
	t_common	*common;
	t_philo		*philo;

	philo = arg;
	common = philo->common;
	while (common->num_must_eat != philo->num_eat)
	{
		if (start_eat_routine(common, philo) == FAIL)
			return (NULL);
		if (common->num_must_eat == philo->num_eat)
			return (NULL);
		if (start_sleep_routine(common, philo) == FAIL)
			return (NULL);
		printf_philo(common, philo->num_philo, "is thinking");
	}
	return (NULL);
}

static void	set_finish_flag(t_common *common)
{
	pthread_mutex_lock(&common->finish_flag_mutex);
	common->finish_flag = 1;
	pthread_mutex_unlock(&common->finish_flag_mutex);
}

/**
 * waits for philosophers thread to finish from main thread
*/
static void	main_thread_join(t_common *common, t_philo *philo_list)
{
	int	i;
	int	status;

	i = -1;
	while (++i < common->num_of_philo)
	{
		status = 0;
		status = pthread_join(philo_list[i].thread, NULL);
		if (status != SUCCESS)
		{
			common->status_code = ERROR;
			set_finish_flag(common);
			print_error(common->status_code);
		}
	}
}

/**
 * extended main execution flow. Initiates each philo threads
*/
void	start_routine(t_common *common, t_philo *philo_list)
{
	int	i;

	i = -1;
	common->start_time = get_cur_time_us();
	while (++i < common->num_of_philo)
	{
		philo_list[i].last_eat_time = common->start_time;
		pthread_create(&philo_list[i].thread, NULL,
			philo_routine, (void *)&philo_list[i]);
	}
	main_thread_join(common, philo_list);
}
