/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:54:16 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:41:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	print_type_2(long address, char *buf);
void	print_to_hex(long i, int cur, int depth);
int		ft_strlen(char *str);

void	write_line(int byte_type, long address, char *buf)
{
	int	i;

	i = 0;
	print_to_hex(address / 16 * 16, 0, 6 + byte_type);
	while (i < 16)
	{
		write(1, " ", 1);
		if (byte_type == 2 && i % 8 == 0)
			write(1, " ", 1);
		if ((address % 16 == 0 && i < 16) || i < address % 16)
			print_to_hex(buf[i], 0, 2);
		else
			write(1, "  ", 2);
		i++;
	}
	if (byte_type == 2)
		print_type_2(address, buf);
	write(1, "\n", 1);
}

void	print_error(char **argv, t_file_dto *dto, int error_code)
{
	if (error_code < 0)
	{
		write(2, basename(argv[0]), ft_strlen(basename(argv[0])));
		write(2, ": ", 2);
		write(2, argv[dto->i], ft_strlen(argv[dto->i]));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	write_stdin1(long address, int flag_star, int *flag)
{
	if (address % 16 == 0 && address != 0 && flag_star == 0 && *flag == 0)
	{
		*flag = 1;
		write(1, "*\n", 2);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	dto_init(t_file_dto *file_dto)
{
	file_dto->i = 1;
	file_dto->address = 0;
	file_dto->flag = 0;
	file_dto->flag_star = 1;
	file_dto->success = 0;
}
