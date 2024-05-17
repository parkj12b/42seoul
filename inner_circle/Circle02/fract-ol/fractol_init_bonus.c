/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:11:53 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 20:54:46 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandelbrot_init(t_fractal *fractal)
{
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->cx = (fractal->x - WIDTH / 2) * fractal->scale + fractal->x_offset;
	fractal->cy = (fractal->y - HEIGHT / 2) * fractal->scale
		+ fractal->y_offset;
	fractal->iteration = 0;
	fractal->magnitude = 0;
}

void	julia_init(t_fractal *fractal)
{
	fractal->zx = (fractal->x - WIDTH / 2.0)
		* fractal->scale + fractal->x_offset;
	fractal->zy = (fractal->y - HEIGHT / 2.0)
		* fractal->scale + fractal->y_offset;
	fractal->iteration = 0;
	fractal->magnitude = 0;
}

void	fractal_init(t_fractal *fractal)
{
	int	i;

	fractal->mlx = mlx_init();
	fractal->mlx_win = mlx_new_window(fractal->mlx, 1920, 1080,
			"minsepar's fract-ol");
	i = -1;
	while (++i < 2)
	{
		fractal->img[i].img = mlx_new_image(fractal->mlx, 1920, 1080);
		fractal->img[i].addr = mlx_get_data_addr(fractal->img[i].img,
				&fractal->img[i].bits_per_pixel, &fractal->img[i].line_length,
				&fractal->img[i].endian);
	}
	fractal->x = WIDTH / 2;
	fractal->y = HEIGHT / 2;
	fractal->x_offset = 0;
	fractal->y_offset = 0;
	fractal->frame_count = 0;
	fractal->type = 0;
	fractal->scale = 6. / WIDTH;
	fractal->cy = 0;
	fractal->cx = 0;
	fractal->init_calculation[0] = mandelbrot_init;
	fractal->init_calculation[1] = julia_init;
	fractal->init_calculation[2] = mandelbrot_init;
}

void	fractal_init2(t_fractal *fractal)
{
	fractal->color = 0x00FF0019;
	fractal->color_section = 0;
	fractal->color_flag = 5;
}
