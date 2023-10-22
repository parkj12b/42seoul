/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:35:44 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/07 12:24:11 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_write(int nb, char *arr, int length)
{
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb > 0)
	{
		write(1, arr + 1, length);
	}
	else
	{
		write(1, arr, length + 1);
	}
}

int	get_length(long n)
{
	int	length;

	length = 0;
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

void	ft_putnbr(int nb)
{
	char	arr[11];
	long	pos_nb;
	int		length;
	int		temp_length;

	arr[0] = '-';
	pos_nb = nb;
	if (nb < 0)
		pos_nb *= -1;
	length = get_length(pos_nb);
	temp_length = length;
	while (pos_nb > 0)
	{
		arr[temp_length] = (pos_nb % 10) + '0';
		pos_nb /= 10;
		temp_length--;
	}
	ft_putnbr_write(nb, arr, length);
}
