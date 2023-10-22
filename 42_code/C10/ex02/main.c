/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:05:05 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:41:06 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "ft.h"

void	print_file_name(char *file_name);
int		is_valid_byte(char **argv, int argc);
void	read_stdin(char *buf, t_dto *t_dto);
void	increase_num(unsigned int *i, int byte_type);
long	char_to_long(char *str, int byte_type, t_dto *t_dto);
void	read_write(char *file_name, long num_bytes, t_dto *t_dto, int argc);
int		ft_strlen(char *str);

void	print_error(char *file_name, t_dto *t_dto)
{
	write(2, basename(t_dto->argv[0]), ft_strlen(basename(t_dto->argv[0])));
	write(2, ": ", 2);
	write(2, file_name, ft_strlen(file_name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	read_write1(t_dto *t_dto, int argc, char *file_name)
{
	if (t_dto->first_print == 1)
		write(1, "\n", 1);
	if ((t_dto->byte_type == 1 && argc >= 4)
		|| (t_dto->byte_type == 2 && argc >= 5))
		print_file_name(file_name);
}

void	read_write2(int j, long num_bytes, char *buf, int *cursor)
{
	if (j <= num_bytes)
		write(1, &buf[*cursor], 1);
	else
		write(1, &buf[(j + *cursor) % num_bytes], 1);
	*cursor = *cursor + 1;
}

void	dto_init(t_dto *t_dto, char **argv)
{
	t_dto->argv = argv;
	t_dto->first_print = 0;
	t_dto->is_zero = 0;
}

int	main(int argc, char **argv)
{
	unsigned int		i;
	int					byte_type;
	char				*buf;
	t_dto				t_dto;

	dto_init(&t_dto, argv);
	i = 1;
	byte_type = is_valid_byte(argv, argc);
	if (byte_type == 0)
		return (0);
	t_dto.num_bytes = char_to_long(argv[byte_type], byte_type, &t_dto);
	buf = (char *)malloc(sizeof(char) * t_dto.num_bytes + 1);
	if (argc == 2 || (argc == 3 && byte_type == 2))
		read_stdin(buf, &t_dto);
	increase_num(&i, byte_type);
	while (i < (unsigned int) argc)
	{
		t_dto.i = i;
		t_dto.byte_type = byte_type;
		read_write(argv[i], t_dto.num_bytes, &t_dto, argc);
		i++;
	}
	free(buf);
}
