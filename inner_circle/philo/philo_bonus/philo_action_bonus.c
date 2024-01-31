/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/31 16:00:34 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	printf_philo(int philo_num, char *message, t_args *t_args)
{
	sem_wait(t_args->print_lock);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, message);
	sem_post(t_args->print_lock);
}

void	philo_eat(t_philo *philo, t_args *t_args)
{
	sem_wait(t_args->half_control_lock);
	sem_wait(t_args->fork);
	printf_philo(philo->philo_num, "has taken a fork", t_args);
	sem_wait(t_args->fork);
	printf_philo(philo->philo_num, "has taken a fork", t_args);
	gettimeofday(&philo->time_last_meal, NULL);
	printf_philo(philo->philo_num, "is eating", t_args);
	ft_usleep(t_args->time_to_eat, philo);
	philo->meal_count++;
	sem_post(t_args->fork);
	sem_post(t_args->fork);
	sem_post(t_args->half_control_lock);
}

void	philo_sleep(t_philo *philo, t_args *t_args)
{
	printf_philo(philo->philo_num, "is sleeping", t_args);
	ft_usleep(t_args->time_to_sleep, philo);
}

void	printf_dead(int philo_num, t_args *t_args)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	sem_wait(t_args->print_lock);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, "died");
}

// int	check_finish_flag(t_args *t_args)
// {
// 	int	return_num;

// 	return_num = 0;
// 	sem_wait(t_args->finish_lock);
// 	if (t_args->finish_flag == 1)
// 		return_num = 1;
// 	sem_post(t_args->finish_lock);
// 	return (return_num);
// }
