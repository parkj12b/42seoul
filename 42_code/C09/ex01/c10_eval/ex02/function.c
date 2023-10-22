/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:16:27 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:37:08 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include "ft.h"

int		ft_strlen(char *str);
int		is_valid_byte(char *argv[], int argc);
int		is_valid_byte2(char *argv[], int byte_type);
void	is_valid_byte_print(char **argv, int byte_type);
void	read_stdin1(unsigned int *cursor, int i, int num_bytes, char *buf);

void	increase_num(unsigned int *i, int byte_type)
{
	if (byte_type == 1)
		*i = *i + 1;
	else
		*i = *i + 2;
}

void	print_file_name(char *file_name)
{
	write(1, "==> ", 4);
	write(1, file_name, ft_strlen(file_name));
	write(1, " <==", 4);
	write(1, "\n", 1);
}

void	read_stdin(char *buf, t_dto *t_dto)
{
	ssize_t			ret;
	unsigned int	i;
	unsigned int	cursor;

	i = 0;
	cursor = 0;
	ret = read(0, &buf[i % t_dto->num_bytes], 1);
	while (ret)
	{
		if (ret != 0)
			i++;
		ret = read(0, &buf[i % t_dto->num_bytes], 1);
	}
	while (cursor < t_dto->num_bytes && cursor < i && !t_dto->is_zero)
	{
		read_stdin1(&cursor, i, t_dto->num_bytes, buf);
		cursor++;
	}
}

int	is_valid_byte(char *argv[], int argc)
{
	int	byte_type;
	int	i;

	i = 0;
	if (ft_strlen(argv[1]) > 2 || argc == 2)
		byte_type = 1;
	else
		byte_type = 2;
	if (argv[1][0] != '-' || argv[1][1] != 'c'
		|| !is_valid_byte2(argv, byte_type))
		return (0);
	if (byte_type == 1)
		i = i + 2;
	while (argv[byte_type][i] != 0)
	{
		if (argv[byte_type][i] < '0' || argv[byte_type][i] > '9')
		{
			is_valid_byte_print(argv, byte_type);
			return (0);
		}
		i++;
	}
	return (byte_type);
}

int	is_valid_byte2(char *argv[], int byte_type)
{
	if (byte_type != 1)
		return (1);
	else
	{
		if (ft_strlen(argv[byte_type]) == 2)
		{
			write(2, basename(argv[0]), ft_strlen(basename(argv[0])));
			write(2, ": option requires an argument -- c\n", 35);
			return (0);
		}
		return (1);
	}
}
