/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:35:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 14:12:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	terminate_program(void)
{
	int	i;

	i = -1;
	kill(0, SIGTERM);
}

static void	parent_wait(t_common *common)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < common->num_of_philo)
	{
		waitpid(0, &wstatus, 0);
		if (WEXITSTATUS(wstatus) != 0)
		{
			terminate_program();
			break ;
		}
	}
}

static t_philo	*init_philo_list(t_common *common)
{
	t_philo	*philo_list;
	int		i;

	philo_list = nul_guard(malloc(sizeof(t_philo) * common->num_of_philo));
	i = -1;
	while (++i < common->num_of_philo)
	{
		init_t_philo(common, &philo_list[i], i + 1);
	}
	return (philo_list);
}

void	parent_routine(t_common *common, t_philo *philo_list)
{
	pthread_t	waiter;
	int			i;

	pthread_create(&waiter, NULL, serve_forks, (void *)philo_list);
	ft_msleep(2000);
	i = -1;
	while (++i < common->num_of_philo)
	{
		sem_post(common->barrier_lock);
	}
	parent_wait(common);
	cleanup_philo(common, philo_list);
}

void	fork_philo(t_common *common)
{
	t_philo		*philo;
	int			i;

	i = -1;
	philo = init_philo_list(common);
	common->start_time = get_cur_time_us();
	common->start_time += 2000000;
	while (++i < common->num_of_philo)
	{
		common->child_pid[i] = fork();
		if (common->child_pid[i] == 0)
		{
			sem_wait(common->barrier_lock);
			sem_wait(philo[i].last_time_lock);
			philo[i].last_eat_time = get_cur_time_us();
			sem_post(philo[i].last_time_lock);
			start_routine(common, &philo[i]);
		}
	}
	if (common->child_pid[0] != 0)
		parent_routine(common, philo);
}
