/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:07 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/21 23:25:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_t_common(t_common *common)
{
	pthread_mutex_destroy(&common->finish_flag_mutex);
	free(common->fork_status);
}
