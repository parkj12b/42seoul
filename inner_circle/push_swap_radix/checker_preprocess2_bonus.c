/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_preprocess2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:50:03 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:04:22 by minsepar         ###   ########.fr       */
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
			throw_error((void **)sorted_list, 0, 0, 0);
	}
}

int	*normalize_list(t_index_node **list, int size)
{
	int				*int_list;
	int				i;

	int_list = (int *)malloc(sizeof(int) * size);
	if (!int_list)
		throw_error((void **)list, 0, 0, 0);
	i = -1;
	while (++i < size)
		list[i]->sorted_index = i;
	i = -1;
	while (++i < size)
		int_list[list[i]->original_index] = list[i]->sorted_index;
	return (int_list);
}

void	alist_to_nodelist_helper(char **parsed_string,
		t_index_node **list, int *size, int malloc_flag)
{
	int	i;

	i = -1;
	while (++i < *size)
	{
		list[i] = (t_index_node *)malloc(sizeof(t_index_node));
		if (!list[i] && malloc_flag)
			throw_error((void **)list, (void **)parsed_string, 0, 0);
		else if (!list[i])
			throw_error((void **)list, 0, 0, 0);
		if (malloc_flag)
			list[i]->value = ft_atoi(parsed_string[i], (void **)list,
					(void **)parsed_string);
		if (!malloc_flag)
			list[i]->value = ft_atoi(parsed_string[i], (void **)list, 0);
		list[i]->original_index = i;
		list[i]->sorted_index = 0;
	}
}

t_index_node	**alist_to_nodelist(char **argv, int *size)
{
	t_index_node	**list;
	char			**parsed_string;
	char			malloc_flag;

	malloc_flag = 0;
	if (*size == 2)
	{
		parsed_string = ft_split(argv[0], ' ');
		malloc_flag = 1;
	}
	else
		parsed_string = argv;
	*size = count_words(parsed_string);
	list = (t_index_node **)ft_calloc(sizeof(t_index_node *), *size);
	if (!list && malloc_flag)
		throw_error((void **)parsed_string, 0, 0, 0);
	else if (!list)
		throw_error(0, 0, 0, 0);
	alist_to_nodelist_helper(parsed_string, list, size, malloc_flag);
	if (malloc_flag)
		ft_free_checker((void **)parsed_string, 0, 0, 0);
	return (list);
}
