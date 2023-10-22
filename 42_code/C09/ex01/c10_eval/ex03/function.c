/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:52:33 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:38:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	print_non_printable(char c)
{
	if ((unsigned char) c < 32 || (unsigned char) c > 126)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

void	print_to_hex(long i, int cur, int depth)
{
	char	*str;

	str = "0123456789abcdef";
	if (cur != depth - 1)
		print_to_hex(i / 16, cur + 1, depth);
	write(1, &str[i % 16], 1);
}

void	get_byte_type(int argc, char *argv[], t_file_dto *t_file_dto)
{
	if (argc > 1 && argv[1][0] == '-'
			&& argv[1][1] == 'C' && argv[1][2] == 0)
	{
		t_file_dto->i = 2;
		t_file_dto->byte_type = 2;
	}
	else
		t_file_dto->byte_type = 1;
}

void	print_type_2(long address, char *buf)
{
	int	i;

	i = 0;
	write(1, "  |", 3);
	while ((address % 16 == 0 && i < 16) || i < address % 16)
	{
		print_non_printable(buf[i]);
		i++;
	}
	write(1, "|", 1);
}
