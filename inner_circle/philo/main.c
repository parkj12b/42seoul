/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:58:04 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/14 21:36:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return ((int)(num * sign));
}

int	init_mutex(t_args *t_args)
{
	int	i;

	t_args->fork = malloc(sizeof(pthread_mutex_t) * t_args->num_philo);
	if (!t_args)
		return (ERROR);
	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_init(&t_args->fork[i], NULL);
	}
	return (0);
}

int	init_t_args(t_args *t_args, int argc, char **argv)
{
	t_args->num_philo = ft_atoi(argv[1]);
	t_args->time_to_die = ft_atoi(argv[2]);
	t_args->time_to_eat = ft_atoi(argv[3]);
	t_args->time_to_sleep = ft_atoi(argv[4]);
	t_args->finished_philo = 0;
	t_args->finish_flag = 0;
	t_args->num_must_eat = -1;
	if (argc == 6)
		t_args->num_must_eat = ft_atoi(argv[5]);
	if (t_args->num_philo <= 0 || t_args->time_to_die < 0
		|| t_args->time_to_eat < 0 || t_args->time_to_sleep < 0
		|| (argc == 6 && t_args->num_must_eat < 0))
		return (ERROR);
	if (init_mutex(t_args) == ERROR)
		return (ERROR);
	return (0);
}

int	print_error(char *message)
{
	printf("./philo: %s\n", message);
	return (ERROR);
}

t_philo	**init_philo(t_args *t_args)
{
	t_philo	**philo;
	int		i;

	philo = malloc(sizeof(t_philo *) * t_args->num_philo);
	if (!philo)
		return (0);
	i = -1;
	while (++i < t_args->num_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->philo_num = i + 1;
		philo[i]->left_fork = i;
		philo[i]->right_fork = i + 1;
		philo[i]->meal_count = 0;
		philo[i]->arg = t_args;
		gettimeofday(&(philo[i]->time_last_meal), NULL);
	}
	philo[i - 1]->right_fork = 0;
	return (philo);
}

void	printf_philo(int philo_num, char *message)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%d %d %s\n", time.tv_usec, philo_num, message);
}

void	philo_eat(t_philo *philo, t_args *t_args)
{
	pthread_mutex_lock(&t_args->fork[philo->left_fork]);
	printf_philo(philo->philo_num, "has taken a fork");
	pthread_mutex_lock(&t_args->fork[philo->right_fork]);
	printf_philo(philo->philo_num, "has taken a fork");
	gettimeofday(&(philo->time_last_meal), NULL);
	printf_philo(philo->philo_num, "is eating");
	usleep(t_args->time_to_eat);
	pthread_mutex_unlock(&t_args->fork[philo->left_fork]);
	pthread_mutex_unlock(&t_args->fork[philo->right_fork]);
}

void	philo_sleep(t_philo *philo, t_args *t_args)
{
	usleep(t_args->time_to_sleep);
	printf_philo(philo->philo_num, "is sleeping");
}

void *philo_routine(void *arg)
{
	t_philo	philo;
	t_args	*t_args;

	philo = *(t_philo *) arg;
	t_args = philo.arg;
	if (philo.philo_num % 2 == 0)
		usleep(1000);
	while (t_args->num_must_eat < 0
		|| philo.meal_count != t_args->num_must_eat)
	{
		if (t_args->num_philo == 1)
			continue ;
		philo_eat(&philo, t_args);
		philo_sleep(&philo, t_args);
		printf_philo(philo.philo_num, "is thinking");
	}
	return (0);
}

int	check_dead_philo(t_philo **philo, t_args *t_args)
{
	struct timeval	now;
	int				i;

	i = -1;
	while (t_args->finish_flag != 1)
	{
		if (t_args->num_must_eat >= 0
			&& t_args->finished_philo == t_args->num_philo)
			break ;
		while (++i < t_args->num_philo)
		{
			if (gettimeofday(&now, NULL) == ERROR)
				return (ERROR);
			if (now.tv_usec - philo[i]->time_last_meal.tv_usec
				>= t_args->time_to_die)
			{
				t_args->finish_flag = 1;
				break ;
			}
		}
	}
	return (0);
}

void	join_thread(t_philo **philo, t_args *t_args)
{
	int i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_join(philo[i]->thread, NULL);
	}
}

int	start_philo(t_philo **philo, t_args *t_args)
{
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		if(pthread_create(&(philo[i]->thread), NULL, philo_routine, philo[i]))
			return (ERROR);
	}
	check_dead_philo(philo, t_args);
	join_thread(philo, t_args);
	return (0);
}

void	free_mutex(t_args *t_args)
{
	int i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_destroy(&(t_args->fork[i]));
	}
	free(t_args->fork);
}

int	main(int argc, char **argv)
{
	t_args	t_args;
	t_philo	**philo;
	int		error_num;

	if (argc != 5 && argc != 6)
		return (print_error("invalid number of arguments"));
	if (init_t_args(&t_args, argc, argv) == ERROR)
		return (print_error("parsing error"));
	philo = init_philo(&t_args);
	if (error_num == ERROR)
	{
		free_mutex(&t_args);
		return (print_error("philo initialize error"));
	}
	error_num = start_philo(philo, &t_args);
	free_mutex(&t_args);
	free(&philo);
	if (error_num == ERROR)
		return (print_error("philo start error"));
}