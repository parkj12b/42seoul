/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:26 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/09 11:57:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	char_map_to_int(t_info *map_info)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if (map_info->char_map[i][j] == map_info->empty_char)
				map_info->map[i][j] = 1;
			else if (map_info->char_map[i][j] == map_info->obstacle_char)
				map_info->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	solve_map(t_info *map_info)
{
	int	i;
	int	j;

	i = map_info->height - 1;
	while (i >= 0)
	{
		j = map_info->width - 1;
		while (j >= 0)
		{
			map_info->map[i][j] = check(i, j, map_info);
			if (map_info->map[i][j] >= map_info->answer)
			{
				map_info->answer = map_info->map[i][j];
				map_info->answer_y = i;
				map_info->answer_x = j;
			}
			j--;
		}
		i--;
	}
}

void	fill_char_map(t_info *ti)
{
	int	i;
	int	j;

	i = 0;
	while (i < ti->answer)
	{
		j = 0;
		while (j < ti->answer)
		{
			ti->char_map[ti->answer_y + i][ti->answer_x + j] = ti->full_char;
			j++;
		}
		i++;
	}
}

void	print_nbr(int num)
{
	char c;

	if (num > 9)
	{
		print_nbr(num/10);
	}
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	solution(t_info *map_info)
{
	int_map_init(map_info);
	char_map_to_int(map_info);
	solve_map(map_info);
	fill_char_map(map_info);
	free_int_map(map_info);
	print_map(map_info);
	print_nbr(map_info->answer);
	write(1, "---------------------\n", 21);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	fd;

	atexit(f);
	if (argc == 1)
	{
		if (!process_map(0))
			print_error();
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				print_error();
				continue ;
			}
			if (!process_map(fd))
				print_error();
			close(fd);
		}
	}
}
