/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:07:53 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/20 23:10:04 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int error_num)
{
	char	*error_msg[10];

	error_msg[0] = "Invalid Error";
	error_msg[1] = "Error";
	error_msg[2] = "Invalid number of arguments";
	error_msg[3] = "Invalid argument";
	error_msg[4] = "pthread";
	printf("%s\n", error_msg[error_num]);
	return (error_num);
}
