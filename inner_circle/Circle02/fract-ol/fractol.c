/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:06:17 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 23:10:39 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractal *fractal)
{
	calculate_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img[fractal->frame_count].img, 0, 0);
	fractal->frame_count = (fractal->frame_count + 1) % 2;
}

void	test_divergence(t_fractal *fractal)
{
	double	temp_x;

	while (fractal->iteration < 100 && fractal->magnitude <= 4)
	{
		temp_x = (fractal->zx * fractal->zx)
			- (fractal->zy * fractal->zy) + fractal->cx;
		fractal->zy = 2 * (fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = temp_x;
		fractal->magnitude = fractal->zy * fractal->zy
			+ fractal->zx * fractal->zx;
		fractal->iteration++;
	}
}

void	test_divergence_ship(t_fractal *fractal)
{
	double	temp_x;

	while (fractal->iteration < 100 && fractal->magnitude <= 4)
	{
		if (fractal->zy < 0)
			fractal->zy *= -1;
		if (fractal->zx < 0)
			fractal->zx *= -1;
		temp_x = (fractal->zx * fractal->zx)
			- (fractal->zy * fractal->zy) + fractal->cx;
		fractal->zy = 2 * (fractal->zx * fractal->zy) + fractal->cy;
		fractal->zx = temp_x;
		fractal->magnitude = fractal->zy * fractal->zy
			+ fractal->zx * fractal->zx;
		fractal->iteration++;
	}
}

void	calculate_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			fractal->init_calculation[fractal->type - 1](fractal);
			if (fractal->type == 3)
				test_divergence_ship(fractal);
			else
				test_divergence(fractal);
			if (fractal->iteration < 100)
				my_mlx_pixel_put(&(fractal->img[fractal->frame_count]),
					fractal->x, fractal->y,
					fractal->color * fractal->iteration);
			else
				my_mlx_pixel_put(&(fractal->img[fractal->frame_count]),
					fractal->x, fractal->y, 0x00000000);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0;
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal_init(&fractal);
	fractal_init2(&fractal);
	parse_input(&fractal, argc, argv);
	render_fractal(&fractal);
	mlx_hook(fractal.mlx_win, 04, 0L, mouse_down, &fractal);
	mlx_hook(fractal.mlx_win, 17, 0L, terminate_program, &fractal);
	mlx_hook(fractal.mlx_win, 02, 0L, key_down, &fractal);
	mlx_loop(fractal.mlx);
}
