/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:01:12 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 20:19:09 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * return: status_code after parsing
*/

int	is_input_valid(t_common *common)
{
	if (common->num_of_philo < 1 || common->time_to_die < 0
		|| common->time_to_eat < 0 || common->time_to_sleep < 0
		|| (common->num_must_eat != -1 && common->num_must_eat < 0))
		return (FALSE);
	return (TRUE);
}

int	parse_input(int argc, char **argv, t_common *common)
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
		|| is_input_valid(common) == FALSE)
	{
		common->status_code = INVARG;
		print_error(INVARG);
		return (INVARG);
	}
	return (SUCCESS);
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
}
