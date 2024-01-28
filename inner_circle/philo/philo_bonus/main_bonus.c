/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:37:48 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/28 17:02:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	throw_error(char *message)
{
	write(2, "./philo: ", 9);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(errno);
}

void	throw_custom_error(char *message, int error_num)
{
	write(2, "./philo: ", 9);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(error_num);
}

void	parent_wait(t_args *t_args)
{
	int	exit_status;
	int	i;

	i = -1;
	while (++i < t_args->num_philo)
	{
		waitpid(-1, &exit_status, 0);
		if (exit_status != 0)
		{
			i = -1;
			while (++i < t_args->num_philo)
			{
				kill(t_args->child_pid[i], SIGKILL);
			}
			break ;
		}
	}
}

void	cleanup(t_args *t_args, t_philo **philo)
{
	int	i;

	i = -1;
	sem_unlink("sem_fork");
	sem_unlink("sem_print_lock");
	sem_unlink("sem_finish_lock");
	while (++i < t_args->num_philo)
	{
		free(philo[i]);
	}
	free(philo);
	free(t_args->child_pid);
}

void	check()
{
	system("leaks philo_bonus");
}

int	main(int argc, char **argv)
{
	atexit(check);
	t_args	t_args;
	t_philo	**philo;

	if (argc != 5 && argc != 6)
		throw_error("invalid number of arguments");
	parse_input(&t_args, argc, argv);
	init_t_args(&t_args);
	philo = init_philo(&t_args);
	start_child(&t_args, philo);
	cleanup(&t_args, philo);
}
