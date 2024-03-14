/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:56:40 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/14 21:39:11 by minsepar         ###   ########.fr       */
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
			return (EFNFAIL);
	}
	check_dead_philo(philo, t_args);
	join_thread(philo, t_args);
	return (SUCCESS);
}

static void	philo_routine_helper(t_philo **philo, t_args **t_args, void **arg)
{
	*philo = (t_philo *) *arg;
	*t_args = (*philo)->arg;
}

void	increment_finished_philo(t_args *t_args)
{
	pthread_mutex_lock(&t_args->finish_count_mutex);
	t_args->finished_philo++;
	pthread_mutex_unlock(&t_args->finish_count_mutex);
}

int	check_philo_finish(t_philo *philo, t_args *t_args)
{
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (t_args->num_must_eat >= 0
		&& philo->meal_count == t_args->num_must_eat)
	{
		pthread_mutex_unlock(&philo->meal_count_mutex);
		increment_finished_philo(t_args);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_count_mutex);
	if (t_args->num_philo == 1)
		printf_philo(philo->philo_num, "has taken a fork", t_args);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_args	*t_args;

	philo_routine_helper(&philo, &t_args, &arg);
	if (check_philo_finish(philo, t_args) == TRUE)
		return (SUCCESS);
	if (t_args->num_philo == 1)
		return (SUCCESS);
	while (check_finish_flag(t_args) == FALSE)
	{
		if (philo_eat(philo, t_args) == ERROR)
			return (NULL);
		if (check_philo_finish(philo, t_args) == TRUE)
			break ;
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
		pthread_join(philo[i]->thread, NULL);
}

int	check_barrier_status(t_args *t_args)
{
	pthread_mutex_lock(&t_args->barrier_mutex);
	if (t_args->barrier_status == 0)
	{
		pthread_mutex_unlock(&t_args->barrier_mutex);
		return (0);
	}
	pthread_mutex_unlock(&t_args->barrier_mutex);
	return (1);
}

void	decrease_philo_at_barrier(t_args *t_args)
{
	pthread_mutex_lock(&t_args->num_philo_at_barrier_mutex);
	t_args->num_philo_at_barrier--;
	if (t_args->num_philo_at_barrier == 0)
	{
		pthread_mutex_lock(&t_args->barrier_mutex);
		t_args->barrier_status = 0;
		pthread_mutex_unlock(&t_args->barrier_mutex);
	}
	pthread_mutex_unlock(&t_args->num_philo_at_barrier_mutex);
}

int	wait_barrier(t_philo *philo, t_args *t_args)
{
	increase_philo_at_barrier(t_args);
	while (check_finish_flag(t_args) == 0)
	{
		if (check_barrier_status(t_args) == 1)
		{
			decrease_philo_at_barrier(t_args);
			return (0);
		}
		usleep(100);
	}
	pthread_mutex_unlock(&t_args->fork[philo->left_fork]);
	pthread_mutex_unlock(&t_args->fork[philo->right_fork]);
	return (ERROR);
}

int	philo_eat(t_philo *philo, t_args *t_args)
{
	if (take_fork(philo, t_args, philo->left_fork) == ERROR)
		return (ERROR);
	if (take_fork(philo, t_args, philo->right_fork) == ERROR)
		return (ERROR);
	if (wait_barrier(philo, t_args) == ERROR)
		return (ERROR);
	printf_philo(philo->philo_num, "is eating", t_args);
	update_last_time_meal(philo);
	increase_meal_count(philo);
	ft_usleep(t_args->time_to_eat);
	release_fork(philo, t_args);
	return (SUCCESS);
}


void	philo_sleep(t_philo *philo, t_args *t_args)
{
	printf_philo(philo->philo_num, "is sleeping", t_args);
	ft_usleep(t_args->time_to_sleep);
}
