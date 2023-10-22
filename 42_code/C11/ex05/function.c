/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:22:24 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/06 13:15:18 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_num(long num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
		return ;
	}
	print_num(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int	minus(int num1, int num2)
{
	return (num1 - num2);
}

int	divide(int num1, int num2)
{
	return (num1 / num2);
}

int	multiply(int num1, int num2)
{
	return (num1 * num2);
}

int	mod(int num1, int num2)
{
	return (num1 % num2);
}
