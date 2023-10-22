/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:50:26 by minsepar          #+#    #+#             */
/*   Updated: 2023/10/21 22:14:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# define MINUS_FLAG 1 << 0
# define PLUS_FLAG 1 << 1
# define SPACE_FLAG 1 << 2
# define ZERO_FLAG 1 << 3
# define HASH_FLAG 1 << 4
# define DOT_FLAG 1 << 5
# define WIDTH 0
# define PRECISION 1
# define PRINT_STR_LEN 2
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_print_dto
{
	size_t		format_idx;
	size_t		print_idx;;
	char		*print_str;
	char		print_type;
	size_t		size;
	int			flag;
	ssize_t		nums[3];
	va_list		ap;
} t_print_dto;

int		ft_printf(const char *format, ...);
void	parse(const char *str);
void	parse_format(t_print_dto *dto, const char *format_str);
void	recur_d(t_print_dto *dto, char *return_str, ssize_t len, long num);
void	recur_p(t_print_dto *dto, char *return_str, ssize_t len,
		unsigned long num);
void	set_num (t_print_dto *dto, char c, int flag);
int		on_error(t_print_dto *dto, void *mem1);

#endif
