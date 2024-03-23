/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:13:52 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 15:55:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_t_common(t_common *common)
{
	common->child_pid = nul_guard(malloc(sizeof(pid_t) * common->num_of_philo));
	common->last_meal_lock_name = "philo_bonus_lml_";
	common->num_eat_lock_name = "philo_bonus_nel_";
	sem_unlink("print_lock");
	sem_unlink("fork");
	sem_unlink("fork_lock");
	common->print_lock = sem_open("print_lock", O_CREAT, 0644, 1);
	common->fork = sem_open("fork", O_CREAT, 0644, common->num_of_philo);
	common->fork_lock = sem_open("fork_lock", O_CREAT, 0644, 1);
}

void	init_last_time_lock(t_common *common,
	t_philo *philo, char *philo_num_str)
{
	size_t	lock_str_len;

	lock_str_len
		= ft_strlen(common->last_meal_lock_name) + ft_strlen(philo_num_str) + 1;
	philo->last_time_lock_str
		= nul_guard(malloc(sizeof(char) * (lock_str_len)));
	philo->last_time_lock_str[0] = 0;
	ft_strlcat(philo->last_time_lock_str, common->last_meal_lock_name,
		ft_strlen(common->last_meal_lock_name) + 1);
	ft_strlcat(philo->last_time_lock_str,
		philo_num_str, lock_str_len);
	sem_unlink(philo->last_time_lock_str);
	philo->last_time_lock
		= sem_open(philo->last_time_lock_str, O_CREAT, 0644, 1);
}

void	init_num_eat_lock(t_common *common,
	t_philo *philo, char *philo_num_str)
{
	size_t	lock_str_len;

	lock_str_len
		= ft_strlen(common->num_eat_lock_name) + ft_strlen(philo_num_str) + 1;
	philo->num_eat_lock_str
		= nul_guard(malloc(sizeof(char) * (lock_str_len)));
	philo->num_eat_lock_str[0] = 0;
	ft_strlcat(philo->num_eat_lock_str, common->num_eat_lock_name,
		ft_strlen(common->num_eat_lock_name));
	ft_strlcat(philo->num_eat_lock_str, philo_num_str,
		lock_str_len);
	sem_unlink(philo->num_eat_lock_str);
	philo->num_eat_lock
		= sem_open(philo->num_eat_lock_str, O_CREAT, 0644, 1);
}

void	init_t_philo(t_common *common, t_philo *philo, int philo_num)
{
	struct timeval	time;
	char			*philo_num_str;

	gettimeofday(&time, NULL);
	philo->last_eat_time = common->start_time;
	philo->common = common;
	philo->philo_num = philo_num;
	philo_num_str = ft_itoa(philo_num);
	init_last_time_lock(common, philo, philo_num_str);
	init_num_eat_lock(common, philo, philo_num_str);
	free(philo_num_str);
	philo->num_eat = 0;
}

void	exit_cleanup(t_common *common)
{
	free(common->child_pid);
	sem_unlink("print_lock");
	sem_unlink("fork");
	sem_unlink("fork_lock");
}
