/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:38:00 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/28 18:03:01 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_args
{
	struct timeval	start_time;
	sem_t			*fork;
	sem_t			*print_lock;
	sem_t			*finish_lock;
	int				*child_pid;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
}	t_args;

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

/* main_bonus.c */
void	throw_error(char *message);
void	throw_custom_error(char *message, int error_num);
void	parent_wait(t_args *t_args);
int		main(int argc, char **argv);

/* philo_action_bonus.c */
void	printf_philo(int philo_num, char *message, t_args *t_args);
void	philo_eat(t_philo *philo, t_args *t_args);
void	philo_sleep(t_philo *philo, t_args *t_args);
void	printf_dead(int philo_num, t_args *t_args);

/* philo_init_bonus.c */
void	init_t_args(t_args *t_args);
void	parse_input(t_args *t_args, int argc, char **argv);
t_philo	**init_philo(t_args *t_args);

/* philo_routine.c */
void	start_child(t_args *t_args, t_philo **philo);
void	philo_routine(t_philo *philo, t_args *t_args);
void	start_monitor(t_philo *philo, t_args *t_args);
void	*monitor(void *arg);

/* philo_utils_bonus.c */
int		ft_atoi(const char *str);
size_t	get_current_time(void);
size_t	get_timestamp(t_args *t_args);
int		ft_usleep(size_t milliseconds);
size_t	ft_strlen(const char *s);

#endif