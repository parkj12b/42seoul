/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:19:04 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/11 20:01:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	print_error(char *file_name, t_dto *t_dto);
void	read_write1(t_dto *t_dto, int argc, char *file_name);
void	read_write2(int j, long num_bytes, char *buf, int *cursor);

void	read_write3(char *file_name, t_dto *t_dto, int argc, ssize_t ret)
{
	read_write1(t_dto, argc, file_name);
	if (ret > 0)
	{
		t_dto->first_print = 1;
	}
}

void	read_write(char *file_name, long num_bytes, t_dto *t_dto, int argc)
{
	int		fd;
	ssize_t	ret;
	int		j;
	int		cursor;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * num_bytes);
	j = 0;
	cursor = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error(file_name, t_dto);
	else
	{
		read_write3(file_name, t_dto, argc, fd);
		ret = read(fd, &buf[j % num_bytes], 1);
		while (ret && ret != -1)
			ret = read(fd, &buf[++j % num_bytes], 1);
		while (cursor < num_bytes && cursor < j && !t_dto->is_zero && ret != -1)
			read_write2(j, num_bytes, buf, &cursor);
		close(fd);
	}
}

long	char_to_long(char *str, int byte_type, t_dto *t_dto)
{
	long	num;

	num = 0;
	if (byte_type == 1)
		str = str + 2;
	while (*str != '\0')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (num == 0)
	{
		t_dto->is_zero = 1;
		return (1);
	}
	return (num);
}
