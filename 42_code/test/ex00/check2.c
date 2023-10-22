/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:08:19 by donha             #+#    #+#             */
/*   Updated: 2023/09/03 14:23:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_used(int p[], int map[9][9], int n);
int	check_4(int *argv[], int index, int n, int map[9][9]);

int	check2(int *argv[], int index, int n, int map[9][9])
{
	if (check_4(argv, p, n, map) == 0)
		return (0);
	if (is_used(p, map, n) == 0)
		return (0);
	return (1);
}

int	check_4(int *argv[], int index, int n, int map[9][9])
{
	int	height;
	int	colup;
	int	coldown;
	int	rowleft;
	int	rowright;

	height = map[p[0]][p[1]];
	colup = argv[p[1]];
	coldown = argv[p[1] + n];
	rowleft = argv[p[0] + 2 * n];
	rowright = argv[p[0] + 3 * n];
	if (height > n - colup + 1 + p[0])
		return (0);
	if (height > n - coldown + 1 + (n - 1 - p[0]))
		return (0);
	if (height > n - rowleft + 1 + p[1])
		return (0);
	if (height > n - rowright + 1 + (n - 1 - p[1]))
		return (0);
	return (1);
}

int	is_used(int p[], int map[9][9], int n)
{
	int	i;
	int	x;
	int	y;
	int	num;

	i = 0;
	x = p[0];
	y = p[1];
	num = map[x][y];
	while (i < n)
	{
		if (map[i][y] == num && i != x)
			return (0);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (map[x][i] == num && i != y)
			return (0);
		i++;
	}
	return (1);
}
