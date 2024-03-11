/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:55 by minsepar          #+#    #+#             */
/*   Updated: 2024/02/04 01:00:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_time_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	gettimeofday(&philo->time_last_meal, NULL);
	pthread_mutex_unlock(&philo->last_meal_mutex);
}
