/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:12:43 by minsepar          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "parser_bonus.h"

void	free_parse_str(t_parse_str *parse_str)
{
	free(parse_str->str);
	parse_str->str = 0;
}

void	init_parse_str(t_parse_str *parse_str)
{
	parse_str->str = malloc(11);
	parse_str->str[10] = 0;
	parse_str->current_index = 0;
	parse_str->malloc_size = 10;
}

void	init_str_node(t_str_node *str_node)
{
	str_node->next = 0;
	str_node->str = 0;
}

void	init_str_list(t_str_list *str_list)
{
	str_list->head = 0;
	str_list->tail = 0;
	str_list->size = 0;
}

void	append_char(t_parse_str *parse_str, char c)
{
	char	*new_malloc;
	int		prev_size;

	if (parse_str->malloc_size == parse_str->current_index)
	{
		prev_size = parse_str->current_index;
		parse_str->malloc_size *= 2;
		new_malloc = malloc(parse_str->malloc_size + 1);
		while (prev_size--)
			new_malloc[prev_size] = parse_str->str[prev_size];
		free(parse_str->str);
		parse_str->str = new_malloc;
	}
	parse_str->str[parse_str->current_index] = c;
	parse_str->current_index++;
	parse_str->str[parse_str->current_index] = 0;
}
