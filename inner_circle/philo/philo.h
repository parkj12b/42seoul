/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:03:37 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/14 21:30:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ERROR 1
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	pthread_mutex_t	*fork;
    int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				start_time;
	int				finished_philo;
	int				finish_flag;
}   t_args;

typedef struct s_philo
{
	struct timeval	time_last_meal;
	pthread_t		thread;
	t_args			*arg;
	int				meal_count;
	int				philo_num;
	int				left_fork;
	int				right_fork;
}	t_philo;

# endif