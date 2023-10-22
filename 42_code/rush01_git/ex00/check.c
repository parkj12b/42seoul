/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:13:05 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/02 20:29:12 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int argv[], int p[2], int n, int map[9][9]);
int	check_col_down(int argv[], int p[2], int n, int map[9][9]);
int	check_row_left(int argv[], int p[2], int n, int map[9][9]);
int	check_row_right(int argv[], int p[2], int n, int map[9][9]);

int	check(int argv[], int p[2], int n, int map[9][9])
{	
	if (check_col_up(argv, p, n, map) == 0)
		return (0);
	if (check_row_left(argv, p, n, map) == 0)
		return (0);
	if (check_col_down(argv, p, n, map) == 0)
		return (0);
	if (check_row_right(argv, p, n, map) == 0)
		return (0);
	return (1);
}

int	check_col_up(int argv[], int p[2], int n, int map[9][9])
{
	int	colup;
	int	count;
	int	max;
	int	i;

	colup = argv[p[1]];
	max = 0;
	i = 0;
	count = 0;
	while (i < n)
	{
		if (map[i][p[1]] > max && map[i][p[1]] != 0)
		{
			count++;
			max = map[i][p[1]];
		}
		i++;
	}
	if (count > colup)
		return (0);
	return (1);
}

int	check_col_down(int argv[], int p[2], int n, int map[9][9])
{
	int	coldown;
	int	count;
	int	max;
	int	i;

	coldown = argv[p[1] + n];
	max = 0;
	i = n - 1;
	count = 0;
	while (i >= 0 && p[0] == n - 1)
	{
		if (map[i][p[1]] > max && map[i][p[1]] != 0)
		{
			count++;
			max = map[i][p[1]];
		}
		i--;
	}
	if (count > coldown)
		return (0);
	return (1);
}

int	check_row_left(int argv[], int p[2], int n, int map[9][9])
{
	int	rowleft;
	int	count;
	int	i;
	int	max;

	rowleft = argv[p[0] + 2 * n];
	count = 0;
	i = 0;
	max = 0;
	while (i < n)
	{
		if (map[p[0]][i] > max && map[p[0]][i] != 0)
		{
			count++;
			max = map[p[0]][i];
		}
		i++;
	}
	if (count > rowleft)
		return (0);
	return (1);
}

int	check_row_right(int argv[], int p[2], int n, int map[9][9])
{
	int	rowright;
	int	count;
	int	i;
	int	max;

	rowright = argv[p[0] + 3 * n];
	i = n - 1;
	count = 0;
	max = 0;
	while (i >= 0 && p[1] == n - 1)
	{
		if (map[p[0]][i] > max && map[p[0]][i] != 0)
		{
			count++;
			max = map[p[0]][i];
		}
		i--;
	}
	if (count > rowright)
		return (0);
	return (1);
}
