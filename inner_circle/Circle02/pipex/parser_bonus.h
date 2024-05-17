/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:06:10 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/04 20:08:26 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

typedef struct s_parse_str
{
	char	*str;
	int		malloc_size;
	int		current_index;
}	t_parse_str;

typedef struct s_str_node
{
	char				*str;
	struct s_str_node	*next;
}	t_str_node;

typedef struct s_str_list
{
	int			size;
	t_str_node	*head;
	t_str_node	*tail;
}	t_str_list;

/* parser_bonus.c */
void		parse_single_char(t_parse_str *parse_str, char **str);
void		parse_double_quote(t_parse_str *parse_str, char **str);
void		parse_single_quote(t_parse_str *parse_str, char **str);
void		parse_single_word(char **str, t_str_list *str_list);
char		**string_parser(char *str);

/* parser_str_list_bonus.c */
void		enqueue(t_str_list *str_list, t_str_node *str_node);
t_str_node	*dequeue(t_str_list *str_list);
void		add_string_node(t_str_list *str_list, t_parse_str *parse_str);
char		**list_to_char_arr(t_str_list *str_list);

/* parse_utils_bonus.c */
void		free_parse_str(t_parse_str *parse_str);
void		init_parse_str(t_parse_str *parse_str);
void		init_str_node(t_str_node *str_node);
void		init_str_list(t_str_list *str_list);
void		append_char(t_parse_str *parse_str, char c);

#endif