/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_str_list_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:15:46 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/04 19:07:32 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "pipex_bonus.h"

void	enqueue(t_str_list *str_list, t_str_node *str_node)
{
	if (!(str_list->head))
	{
		str_list->head = str_node;
		str_list->tail = str_node;
	}
	else
	{
		str_list->tail->next = str_node;
		str_list->tail = str_node;
	}
	str_list->size++;
}

t_str_node	*dequeue(t_str_list *str_list)
{
	t_str_node	*head;

	if (!(str_list->head))
		return (0);
	else
	{
		head = str_list->head;
		str_list->head = head->next;
		if (!(str_list->head))
			str_list->tail = 0;
	}
	str_list->size--;
	return (head);
}

void	add_string_node(t_str_list *str_list, t_parse_str *parse_str)
{
	t_str_node	*str_node;

	str_node = malloc(sizeof(t_str_node));
	str_node->str = ft_substr(parse_str->str, 0, parse_str->current_index);
	free_parse_str(parse_str);
	enqueue(str_list, str_node);
}

char	**list_to_char_arr(t_str_list *str_list)
{
	char		**return_list;
	t_str_node	*node;
	int			i;

	i = 0;
	return_list = malloc(sizeof(char *) * (str_list->size + 1));
	return_list[str_list->size] = 0;
	while (str_list->size > 0)
	{
		node = dequeue(str_list);
		return_list[i] = node->str;
		free(node);
		i++;
	}
	return (return_list);
}
