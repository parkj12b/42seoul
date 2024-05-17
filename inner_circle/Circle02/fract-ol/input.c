/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:13:46 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 20:42:17 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_julia(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2)
		return (0);
	else if (argc > 2 && fractal->type == 2)
	{
		fractal->cx = ft_atof(argv[2]);
		if (argc == 4)
			fractal->cy = ft_atof(argv[3]);
		return (0);
	}
	else
		return (1);
}

void	parse_input(t_fractal *fractal, int argc, char **argv)
{
	if (argc >= 2 && argc <= 4)
	{
		if (ft_strlen(argv[1]) == 1)
		{
			if (argv[1][0] == 'M' || argv[1][0] == 'm')
				fractal->type = 1;
			else if (argv[1][0] == 'j' || argv[1][0] == 'J')
				fractal->type = 2;
			else if (argv[1][0] == 'b' || argv[1][0] == 'B')
				fractal->type = 3;
			else
				print_invalid_arg();
		}
		else
			print_invalid_arg();
		if (parse_julia(fractal, argc, argv) == 1)
			print_invalid_arg();
	}
	else
		print_invalid_arg();
}

void	print_invalid_arg(void)
{
	ft_printf("fractol: invalid argument\n");
	ft_printf("usage: Mandelbrot or Julia [M, m or J, j or B, b]\n");
	ft_printf("\tJulia set options(default is monitor input), [cx, cy]\n");
	exit(1);
}
