/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:14:55 by minsepar          #+#    #+#             */
/*   Updated: 2025/09/17 21:35:38 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	printf("mouse button: %d at (%d, %d)\n", button, x, y);
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

int	key_down(int keypress, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (keypress == 53)
		on_escape(fractal);
	else if (keypress == 123 || keypress == 124
		|| keypress == 125 || keypress == 126)
		render_arrow(keypress, fractal);
	return (1);
}

int	on_escape(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->mlx_win);
	terminate_program(fractal);
	return (1);
}
