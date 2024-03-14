/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:03:37 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/14 21:35:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR -1
# define SUCCESS 0
# define ENUARG 1
# define EPARSE 2
# define EPHILIN 3
# define EPHILST 4
# define EARGVAL 5
# define EFNFAIL 6

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_args
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	finish_count_mutex;
	pthread_mutex_t	barrier_mutex;
	pthread_mutex_t	error_num_mutex;
	pthread_mutex_t	num_philo_at_barrier_mutex;
	struct timeval	start_time;
	int				error_num;
	int				time_to_die;
	int				num_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				finished_philo;
	int				finish_flag;
	int				*fork_status;
	int				barrier_status;
	int				num_philo_at_barrier;
}	t_args;

typedef struct s_philo
{
	struct timeval	time_last_meal;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	meal_count_mutex;
	pthread_t		thread;
	t_args			*arg;
	int				meal_count;
	int				philo_num;
	int				left_fork;
	int				right_fork;
}	t_philo;

/* main.c */
int		print_error(int error_num);
void	free_mutex(t_args *t_args);
void	free_philo_list(t_philo **philo, t_args *t_args);

/* philo_action.c */
void	printf_dead(int philo_num, t_args *t_args);
void	printf_philo(int philo_num, char *message, t_args *t_args);
void	increase_meal_count(t_philo *philo);
void	release_fork(t_philo *philo, t_args *t_args);
int		take_fork(t_philo *philo, t_args *t_args, int fork_num);

/* philo_init.c */
int		init_t_args(t_args *t_args, int argc, char **argv);
int		init_mutex(t_args *t_args);
t_philo	*init_philo(t_args *t_args, int index);
t_philo	**init_philo_list(t_args *t_args);

/* philo_routine1.c */
int		start_philo(t_philo **philo, t_args *t_args);
void	*philo_routine(void *arg);
void	join_thread(t_philo **philo, t_args *t_args);
int		philo_eat(t_philo *philo, t_args *t_args);
void	philo_sleep(t_philo *philo, t_args *t_args);

/* philo_routine2.c */
int		check_dead_philo(t_philo **philo, t_args *t_args);
int		check_finish_flag(t_args *t_args);

/* philo_util.c */
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
size_t	get_timestamp(t_args *t_args);

/* philo_routine3.c */
void	update_last_time_meal(t_philo *philo);

void	increase_philo_at_barrier(t_args *t_args);

#endif