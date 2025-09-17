/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:16:05 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 22:02:36 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recur(int len, long n, int fd)
{
	char	c;
	int		ret;

	c = n % 10 + '0';
	if (len > 1)
		ft_putnbr_recur(len - 1, n /= 10, fd);
	ret = write(fd, &c, 1);
	if (ret == -1)
		exit(1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	long	temp;
	long	temp_2;

	temp = n;
	len = 0;
	if (temp < 0)
	{
		if (write(fd, "-", 1) == -1)
			exit(1);
		temp *= -1;
	}
	if (n == 0)
		len = 1;
	temp_2 = temp;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	ft_putnbr_recur(len, temp_2, fd);
}
