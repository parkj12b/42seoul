/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/22 22:26:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	printf_philo(int philo_num, char *message, t_args *t_args)
{
	struct timeval	time;

	sem_wait(t_args->print_lock);
	gettimeofday(&time, NULL);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, message);
	sem_post(t_args->print_lock);
}

void	philo_eat(t_philo *philo, t_args *t_args)
{
	sem_wait(t_args->fork);
	printf_philo(philo->philo_num, "has taken a fork", t_args);
	sem_wait(t_args->fork);
	printf_philo(philo->philo_num, "has taken a fork", t_args);
	gettimeofday(&philo->time_last_meal, NULL);
	printf_philo(philo->philo_num, "is eating", t_args);
	philo->meal_count++;
	ft_usleep(t_args->time_to_eat);
	sem_post(t_args->fork);
	sem_post(t_args->fork);
}

void	philo_sleep(t_philo *philo, t_args *t_args)
{
	printf_philo(philo->philo_num, "is sleeping", t_args);
	ft_usleep(t_args->time_to_sleep);
}

void	printf_dead(int philo_num, t_args *t_args)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	sem_wait(t_args->print_lock);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, "died");
}
