/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:05:05 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/10 21:20:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>

int	file_not_found(int ret)
{
	if (ret < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	ssize_t	ret;
	char	buf[100000];

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDWR);
		if (!file_not_found(fd))
			return (0);
		ret = read(fd, buf, 100000);
		if (!file_not_found(ret))
			return (0);
		while (ret)
		{
			buf[ret] = 0;
			write(1, buf, ret);
			ret = read(fd, buf, 100000);
		}
		close(fd);
	}
}
