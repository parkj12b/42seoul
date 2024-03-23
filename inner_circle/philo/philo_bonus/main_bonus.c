/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/22 23:51:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	is_input_valid(t_common *common)
{
	if (common->num_of_philo < 1 || common->time_to_die < 0
		|| common->time_to_eat < 0 || common->time_to_sleep < 0
		|| (common->num_must_eat != -1 && common->num_must_eat < 0))
		return (FALSE);
	return (TRUE);
}

static int	parse_input(int argc, char **argv, t_common *common)
{
	memset(common, 0, sizeof(t_common));
	common->num_must_eat = -1;
	if (argc != 5 && argc != 6)
	{
		print_error(ENOARG);
		exit (255 + ENOARG);
	}
	if (ft_atoi_num_only(argv[1], &common->num_of_philo) != SUCCESS
		|| ft_atoi_num_only(argv[2], &common->time_to_die) != SUCCESS
		|| ft_atoi_num_only(argv[3], &common->time_to_eat) != SUCCESS
		|| ft_atoi_num_only(argv[4], &common->time_to_sleep) != SUCCESS
		|| (argc == 6 && ft_atoi_num_only(argv[5],
				&common->num_must_eat) != SUCCESS)
		|| is_input_valid(common) == FALSE)
	{
		print_error(INVARG);
		exit (255 + INVARG);
	}
	return (SUCCESS);
}

int	print_error(int error_num)
{
	char	*error_msg[4];

	error_msg[0] = "Invalid Error";
	error_msg[1] = "Error";
	error_msg[2] = "Invalid number of arguments";
	error_msg[3] = "Invalid argument";
	ft_putstr_fd(error_msg[error_num], 2);
	exit (ERROR);
}

int	main(int argc, char **argv)
{
	t_common	common;

	parse_input(argc, argv, &common);
	init_t_common(&common);
	fork_philo(&common);
	exit_cleanup();
}

