/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:16:14 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/04 10:24:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_valid(char *base, int *is_duplicate);

int	ft_strlen(char *str, int *base);

int	char_to_int(char nbr, char *base);

long	to_decimal_num(char *nbr, char	*base_from, int *from_arr)
{
	int		nbr_len;
	int		base_len;
	int		digit_multiplier;
	int		i;
	long	decimal_num;

	decimal_num = 0;
	nbr_len = ft_strlen(nbr, from_arr);
	base_len = ft_strlen(base_from, from_arr);
	while (nbr_len > 0)
	{
		i = 1;
		digit_multiplier = 1;
		while (i++ < nbr_len)
			digit_multiplier *= base_len;
		decimal_num += digit_multiplier * char_to_int(*nbr, base_from);
		nbr++;
		nbr_len--;
	}
	return (decimal_num);
}

int	to_decimal(char *nbr, char *base_from, int *from_arr)
{
	int		is_negative;
	long	decimal_num;

	is_negative = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			is_negative *= -1;
		nbr++;
	}
	decimal_num = to_decimal_num(nbr, base_from, from_arr);
	decimal_num *= is_negative;
	return ((int)decimal_num);
}

int	decimal_to_buffer(int num, int base_len, char *buf, char *base_to)
{
	int		length;
	long	decimal_num;

	length = 0;
	decimal_num = num;
	if (num < 0)
		decimal_num *= -1;
	if (decimal_num == 0)
		buf[length++] = base_to[0];
	while (decimal_num > 0)
	{
		buf[length] = base_to[decimal_num % base_len];
		decimal_num /= base_len;
		length++;
	}
	return (length);
}

char	*decimal_to_base(int decimal_num, char *base_to, int *to_arr)
{
	char	buf[32];
	char	*return_ptr;
	int		length;
	int		length_cpy;

	length = decimal_to_buffer(decimal_num,
			ft_strlen(base_to, to_arr), buf, base_to);
	length_cpy = length;
	if (decimal_num < 0)
	{
		return_ptr = (char *) malloc(sizeof (char) * (length + 2));
		return_ptr[0] = '-';
		length++;
	}
	else
		return_ptr = (char *) malloc(sizeof (char) * (length + 1));
	while (length_cpy >= 0)
	{
		return_ptr[length - length_cpy] = buf[length_cpy - 1];
		length_cpy--;
	}
	return_ptr[length] = '\0';
	return (return_ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*return_ptr;
	int		from_arr[256];
	int		to_arr[256];
	int		nbr_decimal;
	int		i;

	i = 0;
	while (i < 256)
	{
		from_arr[i] = 0;
		to_arr[i++] = 0;
	}
	if (!is_valid(base_from, from_arr) || !is_valid(base_to, to_arr))
		return (0);
	nbr_decimal = to_decimal(nbr, base_from, from_arr);
	return_ptr = decimal_to_base(nbr_decimal, base_to, to_arr);
	return (return_ptr);
}
