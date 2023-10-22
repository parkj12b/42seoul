/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:40:58 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 10:23:03 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(char *base, int *is_duplicate)
{
	int	i;

	i = 0;
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-' || is_duplicate[(unsigned char) *base]
			|| (*base >= 9 && *base <= 13) || *base == ' ')
			return (0);
		else
			is_duplicate[(unsigned char)*base]++;
		base++;
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int	ft_strlen(char *str, int *base)
{
	int	i;

	i = 0;
	while (base[(unsigned char) *str] && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int	char_to_int(char nbr, char *base)
{
	int	i;

	i = 0;
	while (*base != nbr)
	{
		i++;
		base++;
	}
	return (i);
}
