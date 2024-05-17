/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:21:45 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 15:49:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	terminate_program(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img[0].img);
	mlx_destroy_image(fractal->mlx, fractal->img[1].img);
	exit(0);
}
