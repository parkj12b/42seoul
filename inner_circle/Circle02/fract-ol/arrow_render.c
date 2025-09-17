/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:18:59 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 21:57:10 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_pixel_right(t_arrow *arrow, t_fractal *fractal)
{
	arrow->dst = arrow->data_dst->addr + (fractal->y
			* arrow->data_dst->line_length + fractal->x
			* (arrow->data_dst->bits_per_pixel / 8));
	arrow->from = arrow->data_from->addr + (fractal->y
			* arrow->data_from->line_length + (fractal->x + 10)
			* (arrow->data_from->bits_per_pixel / 8));
}

void	shift_pixel_left(t_arrow *arrow, t_fractal *fractal)
{
	arrow->dst = arrow->data_dst->addr + (fractal->y
			* arrow->data_dst->line_length + fractal->x
			* (arrow->data_dst->bits_per_pixel / 8));
	arrow->from = arrow->data_from->addr + (fractal->y
			* arrow->data_from->line_length + (fractal->x - 10)
			* (arrow->data_from->bits_per_pixel / 8));
}

void	shift_pixel_down(t_arrow *arrow, t_fractal *fractal)
{
	arrow->dst = arrow->data_dst->addr + (fractal->y
			* arrow->data_dst->line_length + fractal->x
			* (arrow->data_dst->bits_per_pixel / 8));
	arrow->from = arrow->data_from->addr + ((fractal->y + 10)
			* arrow->data_from->line_length + fractal->x
			* (arrow->data_from->bits_per_pixel / 8));
}

void	shift_pixel_up(t_arrow *arrow, t_fractal *fractal)
{
	arrow->dst = arrow->data_dst->addr + (fractal->y
			* arrow->data_dst->line_length + fractal->x
			* (arrow->data_dst->bits_per_pixel / 8));
	arrow->from = arrow->data_from->addr + ((fractal->y - 10)
			* arrow->data_from->line_length + fractal->x
			* (arrow->data_from->bits_per_pixel / 8));
}

void	render_arrow(int keypress, t_fractal *fractal)
{
	t_arrow arrow;

	arrow.data_dst = &fractal->img[fractal->frame_count];
	arrow.data_from = &fractal->img[(fractal->frame_count + 1) % 2];

	switch (keypress)
	{
		case 123: case 65361:
			render_arrow_left(&arrow, fractal);
			break;
		case 124: case 65363:
			render_arrow_right(&arrow, fractal);
			break;
		case 125: case 65364:
			render_arrow_down(&arrow, fractal);
			break;
		case 126: case 65362:
			render_arrow_up(&arrow, fractal);
			break;
		default:
			break;
	}
	calculate_fractal_arrow(&arrow, fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img[fractal->frame_count].img, 0, 0);
	fractal->frame_count = (fractal->frame_count + 1) % 2;
}
