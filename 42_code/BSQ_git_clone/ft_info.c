/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:34:15 by ska               #+#    #+#             */
/*   Updated: 2023/09/14 10:05:28 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	get_lenof_oneline(char *buff)
{
	int	len;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\0')
		return (-1);
	return (len);
}

int	init_charmap(t_info *ti)
{
	int	i;

	ti->char_map[0] = (char *)malloc(sizeof(char)
			* ((ti->width + 1) * ti->height));
	if (!ti->char_map[0])
		return (0);
	i = 1;
	while (i < ti->height)
	{
		ti->char_map[i] = ti->char_map[0] + i * (ti->width + 1);
		i++;
	}
	return (1);
}

int	copy_size(char *buff, int size, t_info *ti, int read_height)
{
	int	i;

	if (ti->width == -1)
	{
		ti->width = size;
		if (!init_charmap(ti))
			return (0);
	}
	if (ti->width != size)
		return (0);
	i = 0;
	while (i < size)
	{
		if (buff[i] != ti->empty_char && buff[i] != ti->obstacle_char)
			return (0);
		ti->char_map[read_height][i] = buff[i];
		i++;
	}
	ti->char_map[read_height][i] = 0;
	return (1);
}

int	set_info(char *buff_list, t_info *ti)
{
	int	i;
	int	read_height;
	int	size;

	size = set_firstline(buff_list, ti);
	if (size < 0)
		return (0);
	i = size + 1;
	read_height = 0;
	while (buff_list[i])
	{
		if (read_height == ti->height)
			return (0);
		size = get_lenof_oneline(buff_list + i);
		if (size <= 0)
			return (0);
		if (!copy_size(buff_list + i, size, ti, read_height++))
			return (0);
		i += size + 1;
	}
	return (read_height == ti->height);
}

void	init_info(t_info *ti)
{
	ti->height = -1;
	ti->width = -1;
	ti->char_map = 0;
	ti->empty_char = 0;
	ti->full_char = 0;
	ti->obstacle_char = 0;
}
