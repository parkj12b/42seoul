/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:56:55 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 14:02:51 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_t_mutex(t_common *common)
{
	pthread_mutex_init(&common->finish_flag_mutex, NULL);
	pthread_mutex_init(&common->print_mutex, NULL);
	pthread_mutex_init(&common->philo_at_barrier_mutex, NULL);
	pthread_mutex_init(&common->barrier_flag_mutex, NULL);
	pthread_mutex_init(&common->finished_philo_mutex, NULL);
	return (SUCCESS);
}

int	init_t_common(t_common *common)
{
	int	i;

	common->fork_status = safe_malloc(common,
			sizeof(int) * common->num_of_philo);
	common->fork_status_mutex = safe_malloc(common,
			sizeof(pthread_mutex_t) * common->num_of_philo);
	if (common->fork_status == NULL)
	{
		print_error(common->status_code);
		return (common->status_code);
	}
	i = -1;
	while (++i < common->num_of_philo)
	{
		common->fork_status[i] = i % 2;
		pthread_mutex_init(&common->fork_status_mutex[i], NULL);
	}
	init_t_mutex(common);
	return (SUCCESS);
}

t_philo	*init_philo_list(t_common *common)
{
	t_philo	*philo_list;
	int		i;

	philo_list = safe_malloc(common, sizeof(t_philo) * common->num_of_philo);
	if (philo_list == NULL)
		return (NULL);
	i = -1;
	while (++i < common->num_of_philo)
	{
		philo_list[i].common = common;
		philo_list[i].left_fork = i;
		philo_list[i].right_fork = i + 1;
		philo_list[i].num_philo = i + 1;
		philo_list[i].num_eat = 0;
	}
	philo_list[i - 1].right_fork = 0;
	return (philo_list);
}

void	free_t_common(t_common *common)
{
	pthread_mutex_destroy(&common->finish_flag_mutex);
	free(common->fork_status);
}

void	exit_cleanup(t_common *common, t_philo *philo_list)
{
	free(common->fork_status);
	pthread_mutex_destroy(&common->finish_flag_mutex);
	pthread_mutex_destroy(&common->print_mutex);
	pthread_mutex_destroy(&common->philo_at_barrier_mutex);
	pthread_mutex_destroy(&common->barrier_flag_mutex);
	pthread_mutex_destroy(&common->finished_philo_mutex);
	free(common->fork_status_mutex);
	free(philo_list);
}
