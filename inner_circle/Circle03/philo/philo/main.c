/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:12 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 16:30:14 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_input_valid(t_common *common, int argc)
{
	if (common->num_of_philo < 1 || common->time_to_die < 0
		|| common->time_to_eat < 0 || common->time_to_sleep < 0
		|| (argc == 6 && common->num_must_eat < 0))
		return (FALSE);
	return (TRUE);
}

static int	parse_input(int argc, char **argv, t_common *common)
{
	memset(common, 0, sizeof(t_common));
	common->num_must_eat = -1;
	if (argc != 5 && argc != 6)
	{
		common->status_code = ENOARG;
		print_error(ENOARG);
		return (ENOARG);
	}
	if (ft_atoi_num_only(argv[1], &common->num_of_philo) != SUCCESS
		|| ft_atoi_num_only(argv[2], &common->time_to_die) != SUCCESS
		|| ft_atoi_num_only(argv[3], &common->time_to_eat) != SUCCESS
		|| ft_atoi_num_only(argv[4], &common->time_to_sleep) != SUCCESS
		|| (argc == 6 && ft_atoi_num_only(argv[5],
				&common->num_must_eat) != SUCCESS)
		|| is_input_valid(common, argc) == FALSE)
	{
		common->status_code = INVARG;
		print_error(INVARG);
		return (INVARG);
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
	ft_putstr_fd("\n", 2);
	return (error_num);
}

int	main(int argc, char **argv)
{
	t_common	common;
	t_philo		*philo_list;

	if (parse_input(argc, argv, &common) != SUCCESS)
		return (common.status_code);
	if (init_t_common(&common) != SUCCESS)
		return (common.status_code);
	philo_list = init_philo_list(&common);
	if (philo_list == NULL)
	{
		free_t_common(&common);
		return (common.status_code);
	}
	start_routine(&common, philo_list);
	exit_cleanup(&common, philo_list);
}
