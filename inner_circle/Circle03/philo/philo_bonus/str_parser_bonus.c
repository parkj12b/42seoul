/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:02:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/03/24 01:13:12 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	append_char(t_parse_str *parse_str, char c)
{
	char	*new_malloc;
	int		prev_size;

	if (parse_str->malloc_size == parse_str->cursor)
	{
		prev_size = parse_str->cursor;
		parse_str->malloc_size *= 2;
		new_malloc = malloc(parse_str->malloc_size + 1);
		while (prev_size--)
			new_malloc[prev_size] = parse_str->str[prev_size];
		free(parse_str->str);
		parse_str->str = new_malloc;
	}
	parse_str->str[parse_str->cursor] = c;
	parse_str->cursor++;
	parse_str->str[parse_str->cursor] = 0;
}

void	append_str(t_parse_str *parse_str, char *str)
{
	while (*str)
	{
		append_char(parse_str, *str);
		str++;
	}
	parse_str->str[parse_str->cursor] = 0;
}
