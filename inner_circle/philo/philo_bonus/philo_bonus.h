/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:46:20 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 16:21:30 by minsepar         ###   ########.fr       */
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

typedef struct s_common /* shared data struct */
{
	size_t	start_time;
	sem_t	*fork;
	sem_t	*print_lock;
	sem_t	*fork_lock;
	sem_t	*process_lock;
	pid_t	*child_pid;
	char	*last_meal_lock_name;
	char	*num_eat_lock_name;
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_must_eat;
}	t_common;

typedef struct s_philo /* represent each philo's data */
{
	pthread_t	routine_thread;
	t_common	*common;
	size_t		last_eat_time;
	sem_t		*last_time_lock;
	sem_t		*num_eat_lock;
	char		*last_time_lock_str;
	char		*num_eat_lock_str;
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
void	printf_philo(t_common *common, int philo_num, char *message);

/* utils_bonus2.c */
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* init_free_bonus.c */
void	init_t_common(t_common *common);
void	init_t_philo(t_common *common, t_philo *philo, int philo_num);
void	exit_cleanup(t_common *common);

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

#endif