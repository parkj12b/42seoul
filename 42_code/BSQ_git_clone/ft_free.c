/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:28:48 by ska               #+#    #+#             */
/*   Updated: 2023/09/14 10:05:25 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	free_table_info(t_info *ti, char *buff_list)
{
	if (ti->char_map)
	{
		if (ti->char_map[0])
			free(ti->char_map[0]);
		free(ti->char_map);
	}
	free(buff_list);
}

void	free_int_map(t_info *ti)
{
	if (!ti->map)
		return ;
	if (ti->map[0])
		free(ti->map[0]);
	free(ti->map);
}

int	free_and_return_zero(char *buff)
{
	free(buff);
	return (0);
}
