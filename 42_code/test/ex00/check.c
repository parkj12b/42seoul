/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:13:05 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/03 14:21:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int *argv[], int index, int n, int map[9][9]);
int	check_col_down(int *argv[], int index, int n, int map[9][9]);
int	check_row_left(int *argv[], int index, int n, int map[9][9]);
int	check_row_right(int *argv[], int index, int n, int map[9][9]);

int	check(int *argv[], int index, int n, int map[9][9])
{	
	if (check_col_up(argv, index, n, map) == 0)
		return (0);
	if (check_row_left(argv, index, n, map) == 0)
		return (0);
	if (check_col_down(argv, index, n, map) == 0)
		return (0);
	if (check_row_right(argv, index, n, map) == 0)
		return (0);
	return (1);
}

int	check_col_up(int *argv[], int index, int n, int map[9][9])
{
	int	colup;
	int	count;
	int	max;
	int	i;

	colup = argv[index][0];
	max = 0;
	i = 0;
	count = 0;
	while (i < n)
	{
		if (map[i][argv[index][1]] > max && map[i][argv[index][1]] != 0)
		{
			count++;
			max = map[i][argv[index][1]];
		}
		i++;
	}
	if (count > colup)
		return (0);
	return (1);
}

int	check_col_down(int *argv[], int index, int n, int map[9][9])
{
	int	coldown;
	int	count;
	int	max;
	int	i;

	coldown = argv[index][0];
	max = 0;
	i = n - 1;
	count = 0;
	while (i >= 0)
	{
		if (map[i][argv[index][1] - n] > max && map[i][argv[index][1] - n] != 0)
		{
			count++;
			max = map[i][argv[index][1] - n];
		}
		i--;
	}
	if (count > coldown)
		return (0);
	return (1);
}

int	check_row_left(int *argv[], int index, int n, int map[9][9])
{
	int	rowleft;
	int	count;
	int	i;
	int	max;

	rowleft = argv[index];
	count = 0;
	i = 0;
	max = 0;
	while (i < n)
	{
		if (map[argv[index][1] - 2 * n][i] > max && map[argv[index][1] - 2 * n][i] != 0)
		{
			count++;
			max = map[argv[index][1] - 2 * n][i];
		}
		i++;
	}
	if (count > rowleft)
		return (0);
	return (1);
}

int	check_row_right(int *argv[], int index, int n, int map[9][9])
{
	int	rowright;
	int	count;
	int	i;
	int	max;

	rowright = argv[index];
	i = n - 1;
	count = 0;
	max = 0;
	while (i >= 0 && argv[index][1] - 3 * n == n - 1)
	{
		if (map[argv[index][1] - 3 * n][i] > max && map[argv[index][1] - 3 * n][i] != 0)
		{
			count++;
			max = map[argv[index][1] - 3 * n][i];
		}
		i--;
	}
	if (count > rowright)
		return (0);
	return (1);
}
