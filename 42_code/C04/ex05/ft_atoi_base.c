/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:05:46 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 22:12:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_valid(char *base, int *duplicate)
{
	int	i;

	i = 0;
	if (*base == '\0' || *(base + 1) == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (duplicate[(unsigned char)base[i]] || base[i] == '-'
			|| base[i] == '+' || base[i] == ' ' || (*base >= 9 && *base <= 13))
			return (0);
		duplicate[(unsigned char)base[i]]++;
		i++;
	}
	return (1);
}

int	str_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	base_char_to_int(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

unsigned int	base_to_int(char *str, char *base, int *duplicate)
{
	int				i;
	int				str_length;
	int				base_len;
	int				n;
	unsigned int	sum;

	sum = 0;
	base_len = str_len(base);
	str_length = 0;
	i = 0;
	while (str[i] != '\0' && duplicate[(unsigned char)str[i++]])
		str_length++;
	while (str_length > 0)
	{
		i = str_length - 1;
		n = 1;
		while (i-- > 0)
			n *= base_len;
		sum += n * base_char_to_int(base, *str);
		str++;
		str_length--;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	sum;
	int				is_negative;
	int				duplicate[256];
	int				i;

	i = 0;
	while (i < 256)
		duplicate[i++] = 0;
	is_negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative *= -1;
		str++;
	}
	if (!is_valid(base, duplicate))
		return (0);
	sum = base_to_int(str, base, duplicate);
	return (sum * is_negative);
}
