/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:05:05 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/09 12:58:25 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	ft_strlen(char *str);

void	print_error(char *argv[], int i)
{
	write(2, basename(argv[0]), ft_strlen(basename(argv[0])));
	write(2, ": ", 2);
	write(2, argv[i], ft_strlen(argv[i]));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	read_write(char *argv[], char *buf, int i)
{
	int		fd;
	ssize_t	ret;

	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
	{
		print_error(argv, i);
	}
	else
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
		{
			print_error(argv, i);
		}
		else
		{
			while (ret)
			{
				write(1, buf, ret);
				ret = read(fd, buf, 1);
			}
		}
		close(fd);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

void	read_stdin(char *buf)
{
	int	ret;

	ret = read(0, buf, 1);
	while (ret)
	{
		if (ret > 0)
			write(1, buf, ret);
		ret = read(0, buf, 1);
	}
}

int	main(int argc, char *argv[])
{
	char	buf[1];
	int		i;

	i = 1;
	if (argc == 1)
		read_stdin(buf);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			read_stdin(buf);
		else
			read_write(argv, buf, i);
		i++;
	}
}
