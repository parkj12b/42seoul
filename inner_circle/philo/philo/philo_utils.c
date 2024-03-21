/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:29 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/20 23:28:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_dead(t_common *common, t_philo *philo)
{
	printf("%zu %d is dead\n", get_timestamp_ms(common), philo->num_philo);
}
