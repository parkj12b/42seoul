/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:54:58 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/27 16:58:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_non_printable(int n)
{
	char	buf[2];
	char	*hex;

	hex = "0123456789abcdef";
	buf[0] = hex[n / 16];
	buf[1] = hex[n % 16];
	write(1, buf, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*p;

	p = (unsigned char *) str;
	while (*p != '\0')
	{
		if (*p < 32 || *p > 126)
		{
			write(1, "\\", 1);
			print_non_printable(*p);
		}
		else
		{
			write(1, p, 1);
		}
		p++;
	}
}
