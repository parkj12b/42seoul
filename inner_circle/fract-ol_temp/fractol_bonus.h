/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:06:38 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 20:54:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# define WIDTH 1920
# define HEIGHT 1080
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line_bonus.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_arrow
{
	t_data	*data_dst;
	t_data	*data_from;
	char	*dst;
	char	*from;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
}	t_arrow;

typedef struct s_fractal
{
	unsigned int	color;
	double			scale;
	double			magnitude;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	double			x_offset;
	double			y_offset;
	t_data			img[2];
	void			*mlx;
	void			*mlx_win;
	void			(*init_calculation[3])(struct s_fractal *);
	int				type;
	int				x;
	int				y;
	int				color_section;
	int				color_flag;
	int				iteration;
	int				frame_count;
}	t_fractal;

/* libft */
int			ft_printf(const char *format, ...);

/* arrow_render.c */
void		shift_pixel_right(t_arrow *arrow, t_fractal *fractal);
void		shift_pixel_left(t_arrow *arrow, t_fractal *fractal);
void		shift_pixel_down(t_arrow *arrow, t_fractal *fractal);
void		shift_pixel_up(t_arrow *arrow, t_fractal *fractal);
void		render_arrow(int keypress, t_fractal *fractal);

/* arrow_render2.c */
void		calculate_fractal_arrow(t_arrow *arrow, t_fractal *fractal);
void		render_arrow_left(t_arrow *arrow, t_fractal *fractal);
void		render_arrow_right(t_arrow *arrow, t_fractal *fractal);
void		render_arrow_down(t_arrow *arrow, t_fractal *fractal);
void		render_arrow_up(t_arrow *arrow, t_fractal *fractal);

/* fractol_init.c */
void		mandelbrot_init(t_fractal *fractal);
void		julia_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		fractal_init2(t_fractal *fractal);

/* fractol_init2.c */
void		init_arrow_left(t_arrow *arrow, t_fractal *fractal);
void		init_arrow_right(t_arrow *arrow, t_fractal *fractal);
void		init_arrow_down(t_arrow *arrow, t_fractal *fractal);
void		init_arrow_up(t_arrow *arrow, t_fractal *fractal);

/* fractol_utils.c */
double		ft_atof(const char *str);
void		print_float(int decimal, double x);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* input.c */
void		parse_input(t_fractal *fractal, int argc, char **argv);
void		print_invalid_arg(void);

/* mlx_hooks.c */
int			handle_mousedown(int button, int x, int y, void *param);
int			mouse_down(int button, int x, int y, void *param);
void		on_enter(t_fractal *fractal);
int			key_down(int keypress, void *param);
int			on_escape(t_fractal *fractal);

/* mlx_hooks2.c */
int			terminate_program(t_fractal *fractal);
void		change_color_enter(t_fractal *fractal);

/* fractol.c */
void		render_fractal(t_fractal *fractal);
void		test_divergence(t_fractal *fractal);
void		test_divergence_ship(t_fractal *fractal);
void		calculate_fractal(t_fractal *fractal);

#endif