/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:31:06 by ska               #+#    #+#             */
/*   Updated: 2023/09/14 10:05:35 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_error(void)
{
	write(2, "map error\n", 10);
}

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

void	ft_strncpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src && i++ < size)
		*dest++ = *src++;
	*dest = 0;
}
