/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:58:04 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/14 20:38:49 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int error_num)
{
	static char	*message[7];

	message[0] = "invalid error";
	message[1] = "invalid number of argument";
	message[2] = "parsing error";
	message[3] = "philo initialize error";
	message[4] = "philo start error";
	message[5] = "invalid argument value";
	message[6] = "function call fail";
	write(2, "./philo: ", 9);
	write(2, message[error_num], ft_strlen(message[error_num]));
	write(2, "\n", 1);
	return (error_num);
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
	pthread_mutex_destroy(&t_args->finish_mutex);
	pthread_mutex_destroy(&t_args->finish_count_mutex);
	pthread_mutex_destroy(&t_args->barrier_mutex);
	pthread_mutex_destroy(&t_args->num_philo_at_barrier_mutex);
	free(t_args->fork);
}

void	free_philo_list(t_philo **philo, t_args *t_args)
{
	int	i;

	i = -1;
	while (philo[++i])
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

	if (argc != 5 && argc != 6)
		return (print_error(ENUARG));
	if (init_t_args(&t_args, argc, argv) != 0)
		return (print_error(t_args.error_num));
	philo = init_philo_list(&t_args);
	if (!philo)
	{
		free_mutex(&t_args);
		return (print_error(t_args.error_num));
	}
	error_num = start_philo(philo, &t_args);
	free_philo_list(philo, &t_args);
	free_mutex(&t_args);
	if (t_args.error_num != 0)
		return (print_error(t_args.error_num));
}
