/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:13:52 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 16:38:24 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_t_common(t_common *common)
{
	common->child_pid = nul_guard(malloc(sizeof(pid_t) * common->num_of_philo));
	sem_unlink("print_lock");
	sem_unlink("fork");
	sem_unlink("barrier_lock");
	common->print_lock = sem_open("print_lock", O_CREAT, 0644, 1);
	common->fork = sem_open("fork", O_CREAT, 0644, common->num_of_philo);
	common->parse_str.cursor = 0;
	common->barrier_lock = sem_open("barrier_lock", O_CREAT, 0644, 0);
	common->parse_str.malloc_size = 10;
	common->parse_str.str = malloc(11);
	common->parse_str.str[0] = 0;
}

void	init_last_time_lock(t_philo *philo, char *philo_num_str)
{
	size_t	lock_str_len;

	lock_str_len
		= ft_strlen(LAST_MEAL_LOCK) + ft_strlen(philo_num_str) + 1;
	philo->last_time_lock_str
		= nul_guard(malloc(sizeof(char) * (lock_str_len)));
	philo->last_time_lock_str[0] = 0;
	ft_strlcat(philo->last_time_lock_str, LAST_MEAL_LOCK,
		lock_str_len);
	ft_strlcat(philo->last_time_lock_str,
		philo_num_str, lock_str_len);
	sem_unlink(philo->last_time_lock_str);
	philo->last_time_lock
		= sem_open(philo->last_time_lock_str, O_CREAT, 0644, 1);
}

void	init_num_eat_lock(t_philo *philo, char *philo_num_str)
{
	size_t	lock_str_len;

	lock_str_len
		= ft_strlen(NUM_EAT_LOCK) + ft_strlen(philo_num_str) + 1;
	philo->num_eat_lock_str
		= nul_guard(malloc(sizeof(char) * (lock_str_len)));
	philo->num_eat_lock_str[0] = 0;
	ft_strlcat(philo->num_eat_lock_str,
		NUM_EAT_LOCK, lock_str_len);
	ft_strlcat(philo->num_eat_lock_str, philo_num_str,
		lock_str_len);
	sem_unlink(philo->num_eat_lock_str);
	philo->num_eat_lock
		= sem_open(philo->num_eat_lock_str, O_CREAT, 0644, 1);
}

void	init_self_lock(t_philo *philo, char *philo_num_str)
{
	size_t	lock_str_len;

	lock_str_len
		= ft_strlen(FORK_LOCK) + ft_strlen(philo_num_str) + 1;
	philo->fork_lock_str
		= nul_guard(malloc(sizeof(char) * (lock_str_len)));
	philo->fork_lock_str[0] = 0;
	ft_strlcat(philo->fork_lock_str, FORK_LOCK, lock_str_len);
	ft_strlcat(philo->fork_lock_str, philo_num_str,
		lock_str_len);
	sem_unlink(philo->fork_lock_str);
	philo->fork_lock
		= sem_open(philo->fork_lock_str, O_CREAT, 0644, 0);
}

void	init_t_philo(t_common *common, t_philo *philo, int philo_num)
{
	char			*philo_num_str;

	philo->common = common;
	philo->philo_num = philo_num;
	philo_num_str = ft_itoa(philo_num);
	init_last_time_lock(philo, philo_num_str);
	init_num_eat_lock(philo, philo_num_str);
	init_self_lock(philo, philo_num_str);
	free(philo_num_str);
	philo->num_eat = 0;
}
