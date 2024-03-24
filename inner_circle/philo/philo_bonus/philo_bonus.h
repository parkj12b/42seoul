/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:46:20 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 15:41:31 by minsepar         ###   ########.fr       */
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

# define LAST_MEAL_LOCK "philo_bonus_lml_"
# define NUM_EAT_LOCK "philo_bonus_nel_"
# define FORK_LOCK "philo_bonus_sln_"

typedef struct s_parse_str
{
	char	*str;
	size_t	malloc_size;
	size_t	cursor;
}	t_parse_str;

typedef struct s_common /* shared data struct */
{
	t_parse_str	parse_str;
	size_t		start_time;
	sem_t		*fork;
	sem_t		*print_lock;
	sem_t		*barrier_lock;
	pid_t		*child_pid;
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_must_eat;
}	t_common;

typedef struct s_philo /* represent each philo's data */
{
	pthread_t	routine_thread;
	t_common	*common;
	size_t		last_eat_time;
	sem_t		*last_time_lock;
	sem_t		*num_eat_lock;
	sem_t		*fork_lock;
	char		*last_time_lock_str;
	char		*num_eat_lock_str;
	char		*fork_lock_str;
	int			num_eat;
	int			philo_num;
}	t_philo;

/* main_bonus.c */
int		print_error(int error_num);

/* utils_bonus.c */
int		ft_atoi_num_only(const char *str, int *return_num);
size_t	get_cur_time_us(void);
size_t	get_timestamp_ms(t_common *common);
void	*nul_guard(void *mem);
void	printf_philo(t_common *common, int philo_num, char *message, int lock);

/* utils_bonus2.c */
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

/* free_bonus.c */
void	exit_cleanup(t_common *common);
void	cleanup_philo(t_common *common, t_philo *philo_list);

/* init_bonus.c */
void	init_t_common(t_common *common);
void	init_t_philo(t_common *common, t_philo *philo, int philo_num);
void	init_self_lock(t_philo *philo, char *philo_num_str);

/* itoa_bonus.c */
char	*ft_itoa(int n);

/* fork_philo.c */
void	fork_philo(t_common *common);

/* routine_bonus.c */
void	start_routine(t_common *common, t_philo *philo);

/* philo_util_bonus.c */
void	ft_msleep(int msec);
int		is_dead(t_common *common, t_philo *philo);

/* philo_eat_bonus.c */
void	start_eat_routine(t_common *common, t_philo *philo);
void	take_fork(t_common *common, t_philo *philo);

/* waiter_bonus.c */
void	*serve_forks(void *arg);

/* str_parser_bonus.c */
void	append_char(t_parse_str *parse_str, char c);
void	append_str(t_parse_str *parse_str, char *str);

#endif