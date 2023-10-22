/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:52:08 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/12 00:37:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <libgen.h>

int	ft_strlen(char *str);

void	read_stdin1(unsigned int *cursor, int i, int num_bytes, char *buf)
{
	if (i < num_bytes)
		write(1, &buf[*cursor], 1);
	else
		write(1, &buf[(i + *cursor) % num_bytes], 1);
}

void	is_valid_byte_print(char **argv, int byte_type)
{
	write(2, basename(argv[0]), ft_strlen(basename(argv[0])));
	write(2, ": illegal offset -- ", 20);
	write(2, argv[byte_type], ft_strlen(argv[byte_type]));
	write(2, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
