/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:49:33 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 14:10:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_cleanup(t_common *common)
{
	free(common->child_pid);
	free(common->parse_str.str);
	sem_close(common->fork);
	sem_close(common->print_lock);
	sem_close(common->barrier_lock);
	sem_unlink("print_lock");
	sem_unlink("fork");
	sem_unlink("barrier_lock");
}

void	cleanup_philo(t_common *common, t_philo *philo_list)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < common->num_of_philo)
	{
		philo = &philo_list[i];
		sem_close(philo->last_time_lock);
		sem_close(philo->num_eat_lock);
		sem_close(philo->fork_lock);
		sem_unlink(philo->last_time_lock_str);
		sem_unlink(philo->num_eat_lock_str);
		sem_unlink(philo->fork_lock_str);
		free(philo->last_time_lock_str);
		free(philo->num_eat_lock_str);
		free(philo->fork_lock_str);
	}
}
