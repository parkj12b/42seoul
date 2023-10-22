/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:19:12 by ska               #+#    #+#             */
/*   Updated: 2023/09/12 20:56:29 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_map(t_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->height)
	{
		write(1, map_info->char_map[i], map_info->width);
		write(1, "\n", 1);
		i++;
	}
}

void	f(void)
{
	system("leaks bsq");
}
