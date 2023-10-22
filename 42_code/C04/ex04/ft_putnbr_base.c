/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:13:59 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/29 23:07:17 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(char *str)
{
	int	i;
	int	*duplicate[256];

	i = 0;
	while (i < 256)
		duplicate[i++] = 0;
	i = 0;
	if (*str == '\0' || *(str + 1) == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (duplicate[(unsigned char) str[i]] || str[i] == '-'
			|| str[i] == '+')
			return (0);
		duplicate[(unsigned char)str[i]]++;
		i++;
	}
	return (1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	char			buf[32];
	int				base_length;
	unsigned int	n;

	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		n = (unsigned int)(nbr * -1);
	else
		n = nbr;
	base_length = str_len(base);
	i = 0;
	if (!is_valid(base))
		return ;
	while (n > 0)
	{
		buf[i] = base[n % base_length];
		n /= base_length;
		i++;
	}
	if (nbr < 0)
		write(1, "-", 1);
	while (i > 0)
		write(1, &buf[--i], 1);
}
