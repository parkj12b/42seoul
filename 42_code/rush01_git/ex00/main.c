/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:11:40 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/02 23:06:25 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str);
void	ft_argc_error_check(int argc);
int		check_row_left(int *argv, int *p, int n, int map[9][9]);
int		check_row_right(int *argv, int *p, int n, int map[9][9]);
int		check_col_up(int *argv, int *p, int n, int map[9][9]);
int		check_col_down(int *argv, int *p, int n, int map[9][9]);
int		check_4(int argv[], int p[2], int n, int map[9][9]);
int		check(int argv[], int p[2], int n, int map[9][9]);
int		check2(int argv[], int p[2], int n, int map[9][9]);
int		recursion(int argv[], int p[], int n, int map[9][9]);
int		print_arr(int map[9][9], int n);
int		check_error(int argc, char *argv[]);
int		*char_to_arr(char *argv[]);
int		ft_count(char *argv);

void	reset_map(int map[][9])
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
			map[i][j++] = 0;
		i++;
	}
}

int	main(int argc, char *argv[])
{	
	int	p[2];
	int	map[9][9];
	int	*arr;
	int	n;

	reset_map(map);
	if (check_error(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	p[0] = 0;
	p[1] = 0;
	arr = char_to_arr(argv);
	if (arr == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	n = (ft_count(argv[1]) + 1) / 8;
	if (recursion(arr, p, n, map) == 0)
		write(2, "Error\n", 6);
	free(arr);
	return (0);
}

int	print_arr(int map[9][9], int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = map[i][j++] + '0';
			write(1, &c, 1);
			if (j != n)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

void	set_next_p(int nextP[], int p[])
{
	nextP[0] = p[0] + 1;
	nextP[1] = 0;
}

int	recursion(int argv[], int p[], int n, int map[9][9])
{
	int	num;
	int	flag;
	int	next_p[2];

	num = 1;
	flag = 0;
	next_p[0] = p[0];
	if (p[0] == n)
		return (print_arr(map, n));
	if (p[1] == n - 1)
		set_next_p(next_p, p);
	else
		next_p[1] = p[1] + 1;
	while (num <= n && flag == 0)
	{
		map[p[0]][p[1]] = num;
		if (check(argv, p, n, map) == 1 && check2(argv, p, n, map) == 1)
			flag = recursion(argv, next_p, n, map);
		num++;
	}
	if (flag == 1)
		return (1);
	map[p[0]][p[1]] = 0;
	return (0);
}
