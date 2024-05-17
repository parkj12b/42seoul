/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:01:20 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/01 21:12:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	process_command_error(t_list *stack_a, t_list *stack_b, char *str)
{
	free_list(stack_a);
	free_list(stack_b);
	throw_error(0, 0, str, 0);
}

void	process_command_helper(t_list *stack_a,
			t_list *stack_b, char *str, int *error_flag)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		*error_flag = swap_top(stack_a);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		*error_flag = swap_top(stack_b);
	else if (ft_strncmp("ss\n", str, 3) == 0)
		swap_a_and_b(stack_a, stack_b);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		push_stack(stack_b, stack_a);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		push_stack(stack_a, stack_b);
	else if (ft_strncmp("ra\n", str, 3) == 0)
		*error_flag = rotate_stack(stack_a);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		*error_flag = rotate_stack(stack_b);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rotate_a_and_b(stack_a, stack_b);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		*error_flag = reverse_rotate_stack(stack_a);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		*error_flag = reverse_rotate_stack(stack_b);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		reverse_rotate_a_and_b(stack_a, stack_b);
	else
		process_command_error(stack_a, stack_b, str);
}

void	pass_check(t_list *stack_a, t_list *stack_b)
{
	int			i;
	t_list_node	*cur;

	if (stack_b->size == 0)
	{
		i = -1;
		cur = stack_a->head;
		while (++i < stack_a->size)
		{
			if (cur->index != i)
			{
				write(1, "KO\n", 3);
				return ;
			}
			cur = cur->next;
		}
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "KO\n", 3);
	}
}

void	process_command(t_list *stack_a, t_list *stack_b)
{
	char	*str;
	int		error_flag;

	error_flag = 0;
	str = get_next_line(0);
	while (str)
	{
		process_command_helper(stack_a, stack_b, str, &error_flag);
		free(str);
		str = get_next_line(0);
	}
	pass_check(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
}

int	main(int size, char **argv)
{
	t_list			stack_a;
	t_list			stack_b;
	t_index_node	**sorted_list;
	int				*normalized_list;

	sorted_list = alist_to_nodelist(&argv[1], &size);
	quicksort_list(sorted_list, 0, size - 1);
	check_duplicate(sorted_list, size);
	normalized_list = normalize_list(sorted_list, size);
	free_node_list(sorted_list, size);
	check_sorted(normalized_list, size);
	list_init(&stack_a);
	list_init(&stack_b);
	stack_a_init(&stack_a, normalized_list, size);
	process_command(&stack_a, &stack_b);
}
