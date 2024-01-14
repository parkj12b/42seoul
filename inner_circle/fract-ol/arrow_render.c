/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:18:59 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/30 21:19:38 by minsepar         ###   ########.fr       */
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
	t_arrow	arrow;

	arrow.data_dst = &fractal->img[fractal->frame_count];
	arrow.data_from = &fractal->img[(fractal->frame_count + 1) % 2];
	if (keypress == 123)
		render_arrow_left(&arrow, fractal);
	else if (keypress == 124)
		render_arrow_right(&arrow, fractal);
	else if (keypress == 125)
		render_arrow_down(&arrow, fractal);
	else if (keypress == 126)
		render_arrow_up(&arrow, fractal);
	calculate_fractal_arrow(&arrow, fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img[fractal->frame_count].img, 0, 0);
	fractal->frame_count = (fractal->frame_count + 1) % 2;
}
