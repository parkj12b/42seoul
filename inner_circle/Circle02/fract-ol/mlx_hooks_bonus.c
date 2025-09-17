/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:14:55 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 21:56:38 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	handle_mousedown(int button, int x, int y, void *param)
{
	t_fractal	*fractal;

	if (button != 1)
		return (1);
	fractal = param;
	fractal->cx = (x - WIDTH / 2.0) * fractal->scale;
	fractal->cy = (y - HEIGHT / 2.0) * fractal->scale;
	ft_printf("c = ");
	print_float(4, fractal->cx);
	ft_printf(" + ");
	print_float(4, fractal->cy);
	ft_printf("i\n");
	render_fractal(fractal);
	return (1);
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_fractal	*fractal;
	double		x_old;
	double		y_old;

	fractal = param;
	if (button == 1 && fractal->type == 2)
		return (handle_mousedown(button, x, y, param));
	else if (!(button == 4 || button == 5))
		return (1);
	x_old = (x - WIDTH / 2.0) * fractal->scale + fractal->x_offset;
	y_old = (y - HEIGHT / 2.0) * fractal->scale + fractal->y_offset;
	if (button == 4)
		fractal->scale *= 1.1;
	else if (button == 5)
		fractal->scale /= 1.1;
	fractal->x_offset = x_old - (x - WIDTH / 2.0) * fractal->scale;
	fractal->y_offset = y_old - (y - HEIGHT / 2.0) * fractal->scale;
	render_fractal(fractal);
	return (0);
}

void	on_enter(t_fractal *fractal)
{
	if (fractal->color_flag == 5
		&& ((unsigned char *)&fractal->color)[fractal->color_section] == 255)
	{
		fractal->color_flag = -5;
		fractal->color_section -= 1;
		if (fractal->color_section < 0)
			fractal->color_section = 2;
	}
	else if (fractal->color_flag == -5
		&& ((unsigned char *)&fractal->color)[fractal->color_section] == 0)
	{
		fractal->color_flag = 5;
		fractal->color_section += 2;
		fractal->color_section %= 3;
	}
	change_color_enter(fractal);
	render_fractal(fractal);
}

#include <stdio.h>
int	key_down(int keypress, void *param)
{
	t_fractal *fractal = (t_fractal *)param;

	switch (keypress)
	{
		case 53:    // ESC (Mac)
		case 65307: // ESC (Linux)
			on_escape(fractal);
			break;
		case 36:    // ENTER (Mac)
		case 65293: // ENTER (Linux)
			on_enter(fractal);
			break;
		case 123: case 124: case 125: case 126:     // Arrow keys (Mac)
		case 65361: case 65362: case 65363: case 65364: // Arrow keys (Linux)
			render_arrow(keypress, fractal);
			break;
		default:
			break;
	}
	return (1);
}

int	on_escape(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	terminate_program(fractal);
	return (1);
}
