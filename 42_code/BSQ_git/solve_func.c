/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:47:35 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/13 20:56:04 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	map_init(t_info *map_info)
{
	map_info->dx[0] = 1;
	map_info->dx[1] = 0;
	map_info->dx[2] = 1;
	map_info->dy[0] = 0;
	map_info->dy[1] = 1;
	map_info->dy[2] = 1;
	map_info->answer = 0;
}

int	check(int i, int j, t_info *dto)
{	
	int	k;
	int	check_y;
	int	check_x;
	int	min;

	min = dto->width;
	k = 0;
	if (dto->map[i][j] == 0)
		return (0);
	while (k < 3)
	{
		check_y = i + dto->dy[k];
		check_x = j + dto->dx[k];
		if (check_y >= dto->height || check_x >= dto->width)
			return (1);
		if (dto->map[check_y][check_x] < min)
			min = dto->map[check_y][check_x];
		k++;
	}
	return (min + 1);
}

void	int_map_init(t_info *map_info)
{
	int	i;

	i = 0;
	map_info->map = (int **)malloc(sizeof(int *) * map_info->height);
	while (i < map_info->height)
	{
		map_info->map[i] = (int *)malloc(sizeof(int) * map_info->width);
		i++;
	}
	map_init(map_info);
}

