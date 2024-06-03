/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_preprocess2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:50:03 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/06 20:24:09 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_duplicate(t_index_node **sorted_list, int size)
{
	int				i;

	i = 0;
	while (++i < size)
	{
		if (sorted_list[i]->value == sorted_list[i - 1]->value)
			throw_error();
	}
}

int	*normalize_list(t_index_node **list, int size)
{
	int				*int_list;
	int				i;

	int_list = (int *)malloc(sizeof(int) * size);
	if (!int_list)
		throw_error();
	i = -1;
	while (++i < size)
		list[i]->sorted_index = i;
	i = -1;
	while (++i < size)
		int_list[list[i]->original_index] = list[i]->sorted_index;
	return (int_list);
}

void	alist_to_nodelist_helper(char **parsed_string,
		t_index_node **list, int *size)
{
	int	i;

	i = -1;
	while (++i < *size)
	{
		list[i] = (t_index_node *)malloc(sizeof(t_index_node));
		if (!list[i])
			throw_error();
		list[i]->value = ft_atoi(parsed_string[i]);
		list[i]->original_index = i;
		list[i]->sorted_index = 0;
	}
}

t_index_node	**alist_to_nodelist(char **argv, int *size)
{
	t_index_node	**list;
	int				split_flag;
	char			**parsed_string;

	split_flag = 0;
	if (*size == 2)
	{
		parsed_string = ft_split(argv[0], ' ');
		split_flag = 1;
	}
	else
		parsed_string = argv;
	*size = count_words(parsed_string);
	list = (t_index_node **)ft_calloc(sizeof(t_index_node *), *size);
	if (!list)
		throw_error();
	alist_to_nodelist_helper(parsed_string, list, size);
	if (split_flag == 1)
		ft_2d_free((void **)parsed_string, *size);
	return (list);
}
