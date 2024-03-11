/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:56:40 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/11 23:43:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philo(t_philo **philo, t_args *t_args)
{
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		if (pthread_create(&(philo[i]->thread), NULL, philo_routine, philo[i]))
			return (ERROR);
	}
	check_dead_philo(philo, t_args);
	// join_thread(philo, t_args);
	return (0);
}

static void	philo_routine_helper(t_philo **philo, t_args **t_args, void **arg)
{
	*philo = (t_philo *) *arg;
	*t_args = (*philo)->arg;
	pthread_detach((*philo)->thread);
	if ((*t_args)->num_philo == 1)
		printf_philo((*philo)->philo_num, "has taken a fork", *t_args);
}

void	increment_finished_philo(t_args *t_args)
{
	pthread_mutex_lock(&t_args->finish_count_mutex);
	t_args->finished_philo++;
	pthread_mutex_unlock(&t_args->finish_count_mutex);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_args	*t_args;

	philo_routine_helper(&philo, &t_args, &arg);
	while (t_args->num_philo > 1 && check_finish_flag(t_args) == 0)
	{
		philo_eat(philo, t_args);
		pthread_mutex_lock(&philo->meal_count_mutex);
		if (t_args->num_must_eat >= 0
			&& philo->meal_count == t_args->num_must_eat)
		{
			pthread_mutex_unlock(&philo->meal_count_mutex);
			increment_finished_philo(t_args);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_count_mutex);
		philo_sleep(philo, t_args);
		printf_philo(philo->philo_num, "is thinking", t_args);
	}
	return (0);
}

void	join_thread(t_philo **philo, t_args *t_args)
{
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_join(philo[i]->thread, NULL);
	}
}

void	philo_eat(t_philo *philo, t_args *t_args)
{
	take_fork(philo, t_args, philo->left_fork);
	take_fork(philo, t_args, philo->right_fork);
	printf_philo(philo->philo_num, "is eating", t_args);
	update_last_time_meal(philo);
	increase_meal_count(philo);
	ft_usleep(t_args->time_to_eat);
	release_fork(philo, t_args);
}


void	philo_sleep(t_philo *philo, t_args *t_args)
{
	printf_philo(philo->philo_num, "is sleeping", t_args);
	ft_usleep(t_args->time_to_sleep);
}
