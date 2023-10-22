/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:03:44 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:41:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "ft.h"

void	write_line(int byte_type, long address, char *buf);
void	print_error(char **argv, t_file_dto *dto, int error_code);
void	get_byte_type(int argc, char *argv[], t_file_dto *t_file_dto);
void	print_to_hex(long i, int cur, int depth);
void	write_stdin1(long address, int flag_star, int *flag);
void	dto_init(t_file_dto *file_dto);

void	write_stdin(char *buf, long *address, int byte_type)
{
	int				flag;
	int				flag_star;
	char			c;
	unsigned int	ret;

	flag_star = 1;
	flag = 0;
	c = buf[*address % 16];
	ret = read(0, buf, 1);
	while (ret > 0)
	{
		if (c != buf[*address % 16])
			flag_star = 1;
		*address = *address + 1;
		write_stdin1(*address, flag_star, &flag);
		if (*address % 16 == 0 && *address != 0 && flag_star == 1)
		{
			write_line(byte_type, *address - 16, buf);
			flag_star = 0;
			flag = 0;
		}
		c = buf[*address % 16];
		ret = read(0, &buf[*address % 16], 1);
	}
}

void	write_files1(t_file_dto *dto)
{
	if (dto->address % 16 == 0 && dto->address != 0
		&& dto->flag_star == 0 && dto->flag == 0)
	{
		dto->flag = 1;
		write(1, "*\n", 2);
	}
}

void	bad_file_descriptor(t_file_dto *t_dto, char *argv[])
{
	t_dto->i = t_dto->i - 1;
	if (!t_dto->success)
	{
		read(-1, &t_dto->buf[t_dto->address % 16], 1);
		print_error(argv, t_dto, t_dto->ret);
	}
}

void	write_files(char **argv, t_file_dto *dto)
{
	dto->fd = open(argv[dto->i], O_RDONLY);
	if (dto->fd > 0)
		dto->success = 1;
	dto->c = dto->buf[dto->address % 16];
	print_error(argv, dto, dto->fd);
	dto->ret = read(dto->fd, &dto->buf[dto->address % 16], 1);
	if (dto->fd > 0)
		print_error(argv, dto, dto->ret);
	while (dto->ret > 0 && dto->fd > 0)
	{
		if (dto->c != dto->buf[dto->address % 16])
			dto->flag_star = 1;
		dto->address = dto->address + 1;
		write_files1(dto);
		if (dto->address % 16 == 0 && dto->address != 0 && dto->flag_star == 1)
		{
			write_line(dto->byte_type, dto->address - 16, dto->buf);
			dto->flag_star = 0;
			dto->flag = 0;
		}
		dto->c = dto->buf[dto->address % 16];
		dto->ret = read(dto->fd, &dto->buf[dto->address % 16], 1);
	}
}

int	main(int argc, char *argv[])
{
	t_file_dto	t_file_dto;

	dto_init(&t_file_dto);
	get_byte_type(argc, argv, &t_file_dto);
	t_file_dto.address = 0;
	if (argc == 1 || (argc == 2 && t_file_dto.byte_type == 2))
		write_stdin(t_file_dto.buf, &t_file_dto.address, t_file_dto.byte_type);
	while ((((argc >= 2 && t_file_dto.byte_type == 1)
				|| (argc >= 3 && t_file_dto.byte_type == 2)))
		&& t_file_dto.i < argc)
	{
		write_files(argv, &t_file_dto);
		t_file_dto.i++;
	}
	if ((((argc >= 2 && t_file_dto.byte_type == 1)
				|| (argc >= 3 && t_file_dto.byte_type == 2))
			&& !t_file_dto.success))
		bad_file_descriptor(&t_file_dto, argv);
	if (t_file_dto.address % 16 != 0 && t_file_dto.address != 0)
		write_line(t_file_dto.byte_type, t_file_dto.address, t_file_dto.buf);
	if (t_file_dto.address != 0)
	{
		print_to_hex(t_file_dto.address, 0, 6 + t_file_dto.byte_type);
		write(1, "\n", 1);
	}
}
