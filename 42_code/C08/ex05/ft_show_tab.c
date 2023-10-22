/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:51:02 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/05 20:40:32 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	print_int(int n)
{
	char			i;
	unsigned int	nb;

	nb = n;
	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		print_int(nb / 10);
	i = nb % 10 + '0';
	write(1, &i, 1);
}

void	put_str(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != 0)
	{
		put_str(par->str);
		write(1, "\n", 1);
		print_int(par->size);
		write(1, "\n", 1);
		put_str(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
