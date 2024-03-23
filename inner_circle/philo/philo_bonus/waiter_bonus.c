/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:15:24 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 23:32:05 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	waiter_routine(t_common *common, t_philo *philo_list)
{
	int	i;

	i = 0;
	i %= common->num_of_philo;
	while (1)
	{
		take_fork(common, &philo_list[i]);
		sem_post(philo_list[i].fork_lock);
		i++;
		i %= common->num_of_philo;
	}
}

void	*serve_forks(void *arg)
{
	t_common		*common;
	t_philo			*philo_list;

	philo_list = arg;
	common = philo_list[0].common;
	waiter_routine(common, philo_list);
	return (NULL);
}
