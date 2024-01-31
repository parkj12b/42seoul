/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:03:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/30 20:53:59 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_dead(int philo_num, t_args *t_args)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	pthread_mutex_lock(&t_args->print_mutex);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, "died");
	pthread_mutex_unlock(&t_args->print_mutex);
}

void	printf_philo(int philo_num, char *message, t_args *t_args)
{
	struct timeval	time;

	pthread_mutex_lock(&t_args->print_mutex);
	if (check_finish_flag(t_args) == 1)
	{
		pthread_mutex_unlock(&t_args->print_mutex);
		return ;
	}
	gettimeofday(&time, NULL);
	printf("%zu %d %s\n", get_timestamp(t_args), philo_num, message);
	pthread_mutex_unlock(&t_args->print_mutex);
}

void	take_fork(t_philo *philo, t_args *t_args, int fork_num)
{
	while (1)
	{
		pthread_mutex_lock(&t_args->fork[fork_num]);
		if (t_args->fork_status[fork_num] == 0 && philo->right_fork == fork_num)
		{
			printf_philo(philo->philo_num, "has taken a fork", t_args);
			return ;
		}
		else if (t_args->fork_status[fork_num] == 1 && philo->left_fork == fork_num)
		{
			printf_philo(philo->philo_num, "has taken a fork", t_args);
			return ;
		}
		pthread_mutex_unlock(&t_args->fork[fork_num]);
		usleep(100);
	}
}

void	release_fork(t_philo *philo, t_args *t_args)
{
	t_args->fork_status[philo->left_fork]++;
	t_args->fork_status[philo->left_fork] %= 2;
	t_args->fork_status[philo->right_fork]++;
	t_args->fork_status[philo->right_fork] %= 2;
	pthread_mutex_unlock(&t_args->fork[philo->right_fork]);
	pthread_mutex_unlock(&t_args->fork[philo->left_fork]);
}

void	increase_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->meal_count_mutex);
}

void	update_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	gettimeofday(&(philo->time_last_meal), NULL);
	pthread_mutex_unlock(&philo->last_meal_mutex);
}

void	philo_eat(t_philo *philo, t_args *t_args)
{
	take_fork(philo, t_args, philo->left_fork);
	take_fork(philo, t_args, philo->right_fork);
	printf_philo(philo->philo_num, "is eating", t_args);
	update_eat_time(philo);
	increase_meal_count(philo);
	ft_usleep(t_args->time_to_eat);
	release_fork(philo, t_args);
}

void	philo_sleep(t_philo *philo, t_args *t_args)
{
	printf_philo(philo->philo_num, "is sleeping", t_args);
	ft_usleep(t_args->time_to_sleep);
	usleep(100);
}
