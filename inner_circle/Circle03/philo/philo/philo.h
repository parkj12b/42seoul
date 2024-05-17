/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:57:46 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 23:50:25 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAIL 1
# define FORK_BUSY 2

/* error_code */
# define ERROR 1
# define ENOARG 2
# define INVARG 3

typedef struct s_common /* shared data struct */
{
	pthread_mutex_t	finish_flag_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	philo_at_barrier_mutex;
	pthread_mutex_t	barrier_flag_mutex;
	pthread_mutex_t	finished_philo_mutex;
	pthread_mutex_t	*fork_status_mutex;
	size_t			start_time;
	int				philo_at_barrier;
	int				barrier_flag;
	int				status_code;
	int				finish_flag;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				finished_philo;
	int				*fork_status;
}	t_common;

typedef struct s_philo /* represent each philo's data */
{
	t_common		*common;
	size_t			last_eat_time;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	int				num_philo;
	int				num_eat;
}	t_philo;

/* utils.c */
int		ft_atoi_num_only(const char *str, int *return_num);
void	*safe_malloc(t_common *common, size_t size);
size_t	get_cur_time_us(void);
size_t	get_timestamp_ms(t_common *common);
void	printf_philo(t_common *common, int philo_num, char *message);

/* utils2.c */
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

/* philo_utils.c */
int		is_finished(t_common *common);
int		is_dead(t_common *common, t_philo *philo);
int		is_in_action(size_t start_time, size_t duration_ms);

/* philo_eat.c */
int		start_eat_routine(t_common *common, t_philo *philo);

/* barrier.c */
int		wait_at_barrier(t_common *common, t_philo *philo);

/* routine.c */
void	start_routine(t_common *common, t_philo *philo_list);

/* init_free.c */
int		init_t_common(t_common *common);
t_philo	*init_philo_list(t_common *common);
void	free_t_common(t_common *common);
void	exit_cleanup(t_common *common, t_philo *philo_list);

/* take_fork.c */
int		take_fork(t_common *common, t_philo *philo, int fork_num);

/* main.c */
int		print_error(int error_num);

#endif