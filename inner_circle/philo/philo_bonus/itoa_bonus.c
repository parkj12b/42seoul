/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:19:51 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/23 16:25:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_ilen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_helper(long n, char *str, int index)
{
	if (n == 0)
		str[index] = '0';
	while (n > 0)
	{
		str[index] = n % 10 + '0';
		index--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;
	long	n_l;

	sign = 0;
	len = 0;
	n_l = n;
	if (n < 0)
	{
		len = 1;
		sign = 1;
		n_l *= -1;
	}
	len += ft_ilen(n_l);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (sign)
		str[0] = '-';
	ft_itoa_helper(n_l, str, len - 1);
	str[len] = 0;
	return (str);
}
