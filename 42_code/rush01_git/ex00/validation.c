/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kang <jae-kang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:24:39 by jae-kang          #+#    #+#             */
/*   Updated: 2023/09/02 22:57:37 by jae-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	*char_to_arr(char *argv[])
{
	int	count;
	int	*arr;

	count = ft_count(argv[1]) + 1;
	count /= 2;
	arr = (int *) malloc(sizeof(int) * count);
	if (arr == NULL)
		return (0);
	count = 0;
	while (argv[1][count] != '\0')
	{
		if (count % 2 == 0)
			arr[count / 2] = argv[1][count] - '0';
		count++;
	}
	return (arr);
}
