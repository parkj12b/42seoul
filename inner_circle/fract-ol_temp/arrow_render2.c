/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_render2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:20:06 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 20:52:17 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal_arrow(t_arrow *arrow, t_fractal *fractal)
{
	while (fractal->y < arrow->y_end)
	{
		while (fractal->x < arrow->x_end)
		{
			fractal->init_calculation[fractal->type - 1](fractal);
			if (fractal->type == 3)
				test_divergence_ship(fractal);
			else
				test_divergence(fractal);
			if (fractal->iteration < 100)
				my_mlx_pixel_put(&(fractal->img[fractal->frame_count]),
					fractal->x, fractal->y, fractal->color
					* fractal->iteration);
			else
				my_mlx_pixel_put(&(fractal->img[fractal->frame_count]),
					fractal->x, fractal->y, 0x00000000);
			fractal->x++;
		}
		fractal->x = arrow->x_start;
		fractal->y++;
	}
}

void	render_arrow_left(t_arrow *arrow, t_fractal *fractal)
{
	fractal->x = 10;
	fractal->y = 0;
	while (fractal->x < 1920)
	{
		while (fractal->y < 1080)
		{
			shift_pixel_left(arrow, fractal);
			*(unsigned int *)arrow->dst = *(unsigned int *)arrow->from;
			fractal->y++;
		}
		fractal->y = 0;
		fractal->x++;
	}
	fractal->x_offset -= fractal->scale * 10;
	init_arrow_left(arrow, fractal);
}

void	render_arrow_right(t_arrow *arrow, t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < 1910)
	{
		while (fractal->y < 1080)
		{
			shift_pixel_right(arrow, fractal);
			*(unsigned int *)arrow->dst = *(unsigned int *)arrow->from;
			fractal->y++;
		}
		fractal->y = 0;
		fractal->x++;
	}
	fractal->x_offset += fractal->scale * 10;
	init_arrow_right(arrow, fractal);
}

void	render_arrow_down(t_arrow *arrow, t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < 1920)
	{
		while (fractal->y < 1070)
		{
			shift_pixel_down(arrow, fractal);
			*(unsigned int *)arrow->dst = *(unsigned int *)arrow->from;
			fractal->y++;
		}
		fractal->y = 0;
		fractal->x++;
	}
	fractal->y_offset += fractal->scale * 10;
	init_arrow_down(arrow, fractal);
}

void	render_arrow_up(t_arrow *arrow, t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 10;
	while (fractal->x < 1920)
	{
		while (fractal->y < 1080)
		{
			shift_pixel_up(arrow, fractal);
			*(unsigned int *)arrow->dst = *(unsigned int *)arrow->from;
			fractal->y++;
		}
		fractal->y = 10;
		fractal->x++;
	}
	fractal->y_offset -= fractal->scale * 10;
	init_arrow_up(arrow, fractal);
}
