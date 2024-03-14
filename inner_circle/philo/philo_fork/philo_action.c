/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:03:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/14 22:44:14 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_dead(int philo_num, t_args *t_args)
{
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

void	increase_philo_at_barrier(t_args *t_args)
{
	pthread_mutex_lock(&t_args->num_philo_at_barrier_mutex);
	t_args->num_philo_at_barrier++;
	pthread_mutex_lock(&t_args->finish_count_mutex);
	if (t_args->num_philo_at_barrier
		== (t_args->num_philo) / 2
		|| t_args->num_philo_at_barrier == (t_args->num_philo - t_args->finished_philo))
	{
		pthread_mutex_lock(&t_args->barrier_mutex);
		t_args->barrier_status = 1;
		pthread_mutex_unlock(&t_args->barrier_mutex);
	}
	pthread_mutex_unlock(&t_args->finish_count_mutex);
	pthread_mutex_unlock(&t_args->num_philo_at_barrier_mutex);
}

int	take_fork(t_philo *philo, t_args *t_args, int fork_num)
{
	while (check_finish_flag(t_args) == 0)
	{
		pthread_mutex_lock(&t_args->fork[fork_num]);
		if (t_args->fork_status[fork_num] == 0 && philo->right_fork == fork_num)
		{
			printf_philo(philo->philo_num, "has taken a fork", t_args);
			return (0);
		}
		else if (t_args->fork_status[fork_num] == 1
			&& philo->left_fork == fork_num)
		{
			printf_philo(philo->philo_num, "has taken a fork", t_args);
			return (0);
		}
		pthread_mutex_unlock(&t_args->fork[fork_num]);
		usleep(t_args->time_to_eat / 2);
	}
	return (ERROR);
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