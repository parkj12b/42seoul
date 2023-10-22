/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_firstline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ska <ska@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:36:45 by ska               #+#    #+#             */
/*   Updated: 2023/09/14 10:05:38 by ska              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	get_firstline_size(char *buff_list)
{
	int	i;

	i = 0;
	while (buff_list[i] && buff_list[i] != '\n')
		i++;
	return (i);
}

int	get_height(char *buff_list, int size)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while ('0' <= buff_list[i] && buff_list[i] <= '9' && i < size)
	{
		res = res * 10 + buff_list[i] - '0';
		if (res > 2147483647)
			return (-1);
		i++;
	}
	if (i != size)
		return (-1);
	return (res);
}

int	examine_characters(t_info *ti)
{
	if (ti->full_char < 32 || ti->full_char > 126)
		return (-1);
	if (ti->obstacle_char < 32 || ti->obstacle_char > 126)
		return (-1);
	if (ti->empty_char < 32 || ti->obstacle_char > 126)
		return (-1);
	if (ti->full_char == ti->obstacle_char)
		return (-1);
	if (ti->full_char == ti->empty_char)
		return (-1);
	if (ti->obstacle_char == ti->empty_char)
		return (-1);
	return (0);
}

int	set_firstline(char *buff_list, t_info *ti)
{
	int	i;
	int	size;

	size = get_firstline_size(buff_list);
	if (size < 4)
		return (-1);
	ti->full_char = buff_list[size - 1];
	ti->obstacle_char = buff_list[size - 2];
	ti->empty_char = buff_list[size - 3];
	if (examine_characters(ti) == -1)
		return (-1);
	ti->height = get_height(buff_list, size - 3);
	if (ti->height <= 0)
		return (-1);
	ti->char_map = (char **)malloc(sizeof(char *)
			* ((unsigned int)ti->height + 1));
	if (!ti->char_map)
		return (-1);
	i = 0;
	while (i < ti->height + 1)
		ti->char_map[i++] = 0;
	return (size);
}
