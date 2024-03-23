/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:35:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 15:09:06 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	terminate_program(t_common *common)
{
	int	i;

	i = -1;
	while (++i < common->num_of_philo)
	{
		kill(common->child_pid[i], SIGKILL);
	}
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
			terminate_program(common);
			break ;
		}
	}
}

void	fork_philo(t_common *common)
{
	t_philo	philo;
	int		i;

	i = -1;
	common->start_time = get_cur_time_us();
	while (++i < common->num_of_philo)
	{
		common->child_pid[i] = fork();
		if (common->child_pid[i] == 0)
		{
			init_t_philo(common, &philo, i + 1);
			start_routine(common, &philo);
		}
	}
	if (common->child_pid[0] != 0)
		parent_wait(common);
}
