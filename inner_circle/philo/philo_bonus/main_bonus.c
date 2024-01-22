/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:37:48 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/22 18:32:06 by minsepar         ###   ########.fr       */
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
			kill(0, SIGKILL);
	}
}

void	check()
{
	system("leaks philo_bonus");
}

int	main(int argc, char **argv)
{
	t_args	t_args;
	t_philo	**philo;


	atexit(check);
	if (argc != 5 && argc != 6)
		throw_error("invalid number of arguments");
	parse_input(&t_args, argc, argv);
	init_t_args(&t_args);
	philo = init_philo(&t_args);
	start_child(&t_args, philo);
}
