/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:24:39 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/03 13:52:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_error(int argc, char *argv[])
{
	int	i;
	int	count;

	if (argc != 2)
		return (0);
	i = 0;
	count = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
				return (0);
			count++;
		}
		else
			if (argv[1][i] != ' ')
				return (0);
		i++;
	}
	if (count % 4 != 0 || count < 16 || count > 36)
		return (0);
	return (1);
}

int	ft_count(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
		i++;
	return (i);
}

int	**sort_arr(int *arr[2], int size)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i][0] < arr[j][0])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	**char_to_arr(char *argv[])
{
	int	count;
	int	**arr;
	int	*pair;

	count = ft_count(argv[1]) + 1;
	count /= 2;
	arr = (int **) malloc(sizeof(int *) * count * 2);
	if (arr == NULL)
		return (0);
	count = 0;
	while (argv[1][count] != '\0')
	{
		if (count % 2 == 0)
		{
			pair = (int *)malloc(sizeof(int) * 2);
			pair[0] = argv[1][count] - '0';
			pair[1] = count / 2;
			arr[count/2] = pair;
		}
		count++;
	}
	arr = sort_arr(arr, (count + 1) / 2);
	return (arr);
}