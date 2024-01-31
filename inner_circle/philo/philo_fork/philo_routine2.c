/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:00:53 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/30 20:34:45 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_philo_dead(t_philo *philo, t_args *t_args)
{
	struct timeval	now;
	ssize_t			diff;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&philo->last_meal_mutex);
	diff = (now.tv_sec - philo->time_last_meal.tv_sec) * 1000000
		+ (now.tv_usec - philo->time_last_meal.tv_usec);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (diff >= t_args->time_to_die * 1000)
	{
		pthread_mutex_lock(&t_args->finish_mutex);
		t_args->finish_flag = 1;
		pthread_mutex_unlock(&t_args->finish_mutex);
		printf_dead(philo->philo_num, t_args);
		printf("died time: %zu\n", diff);
		return (1);
	}
	return (0);
}

int	check_dead_philo(t_philo **philo, t_args *t_args)
{
	int	i;

	while (t_args->finish_flag != 1)
	{
		if (t_args->num_must_eat >= 0
			&& t_args->finished_philo == t_args->num_philo)
			break ;
		i = -1;
		while (++i < t_args->num_philo)
		{
			if (is_philo_dead(philo[i], t_args))
				break ;
		}
	}
	return (0);
}

int	check_finish_flag(t_args *t_args)
{
	int	return_num;

	return_num = 0;
	pthread_mutex_lock(&t_args->finish_mutex);
	if (t_args->finish_flag == 1)
		return_num = 1;
	pthread_mutex_unlock(&t_args->finish_mutex);
	return (return_num);
}
