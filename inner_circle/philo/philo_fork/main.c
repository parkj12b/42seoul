/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:58:04 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/11 23:41:03 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *message)
{
	write(2, "./philo: ", 9);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	return (ERROR);
}

void	free_mutex(t_args *t_args)
{
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_destroy(&(t_args->fork[i]));
	}
	pthread_mutex_destroy(&t_args->print_mutex);
	free(t_args->fork);
}

void	free_philo(t_philo **philo, t_args *t_args)
{
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		pthread_mutex_destroy(&(philo[i]->last_meal_mutex));
		pthread_mutex_destroy(&(philo[i]->meal_count_mutex));
		free(philo[i]);
	}
	free(t_args->fork_status);
	free(philo);
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
	if (!philo)
	{
		free_mutex(&t_args);
		return (print_error("philo initialize error"));
	}
	error_num = start_philo(philo, &t_args);
	free_philo(philo, &t_args);
	free_mutex(&t_args);
	if (error_num == ERROR)
		return (print_error("philo start error"));
}
