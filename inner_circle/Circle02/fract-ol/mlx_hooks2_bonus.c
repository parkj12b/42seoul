/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:21:45 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 15:35:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	terminate_program(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img[0].img);
	mlx_destroy_image(fractal->mlx, fractal->img[1].img);
	exit(0);
}

void	change_color_enter(t_fractal *fractal)
{
	int	new_color_section;

	new_color_section = ((unsigned char *)&fractal->color)
	[fractal->color_section];
	new_color_section += fractal->color_flag;
	fractal->color &= (0x00FFFFFF ^ (0xFF << (fractal->color_section * 8)));
	fractal->color |= new_color_section << (fractal->color_section * 8);
}
