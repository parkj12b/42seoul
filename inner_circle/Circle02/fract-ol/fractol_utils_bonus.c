/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:12:56 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 20:42:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_atof(const char *str)
{
	double	return_num;
	double	decimal_multiplier;

	return_num = ft_atoi(str);
	decimal_multiplier = 0.1;
	if (return_num < 0)
		decimal_multiplier *= -1;
	while (*str && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			return_num += (*str - '0') * decimal_multiplier;
			decimal_multiplier /= 10;
			str++;
		}
	}
	if (*str)
		print_invalid_arg();
	return (return_num);
}

void	print_float(int decimal, double x)
{
	int	num;

	num = (int) x;
	ft_printf("%d", num);
	x -= num;
	if (x != 0)
	{
		ft_printf(".");
		if (x < 0)
			x *= -1;
		while (decimal-- > 0)
		{
			x *= 10;
			ft_printf("%d", (int)x);
			x = x - (int)x;
		}
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
