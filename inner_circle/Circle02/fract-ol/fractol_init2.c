/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:17:17 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/30 21:17:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_arrow_left(t_arrow *arrow, t_fractal *fractal)
{
	arrow->x_start = 0;
	arrow->x_end = 10;
	arrow->y_start = 0;
	arrow->y_end = 1080;
	fractal->x = 0;
	fractal->y = 0;
}

void	init_arrow_right(t_arrow *arrow, t_fractal *fractal)
{
	arrow->x_start = 1910;
	arrow->x_end = 1920;
	arrow->y_start = 0;
	arrow->y_end = 1080;
	fractal->x = 1910;
	fractal->y = 0;
}

void	init_arrow_down(t_arrow *arrow, t_fractal *fractal)
{
	arrow->x_start = 0;
	arrow->x_end = 1920;
	arrow->y_start = 1070;
	arrow->y_end = 1080;
	fractal->x = 0;
	fractal->y = 1070;
}

void	init_arrow_up(t_arrow *arrow, t_fractal *fractal)
{
	arrow->x_start = 0;
	arrow->x_end = 1920;
	arrow->y_start = 0;
	arrow->y_end = 10;
	fractal->x = 0;
	fractal->y = 0;
}
