/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:43:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/06 20:16:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int					index;
	int					cur_digit;
	int					normalized_index;
	int					original_index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	int				size;
	char			list_type;
	t_stack_node	*head;
	t_stack_node	*last;
}	t_stack;

typedef struct s_index_node
{
	int	value;
	int	original_index;
	int	sorted_index;
}	t_index_node;

/* main.c */
void			check_duplicate(t_index_node **sorted_list, int size);
int				check_sorted(int *normalized_list, int size);
void			list_init(t_stack *list, char type);

/* push_swap_preprocess.c */
void			alist_to_nodelist_helper(char **parsed_string,
					t_index_node **list, int *size);
t_index_node	**alist_to_nodelist(char **argv, int *size);
void			swap_index_node_value(t_index_node **list, int i, int j);
int				partition(t_index_node **list, int low, int high);
void			quicksort_list(t_index_node **list, int low, int high);

/* push_swap_preprocess2.c */
int				*normalize_list(t_index_node **list, int size);
void			preprocess_normalization(t_stack *stack, int *order_list);
void			set_original_index(t_stack *stack_copied);
void			set_order_list(t_stack *sorted_stack, int *order_list);
void			preprocess_under_108(t_stack *stack);

/* push_swap_preprocess3.c */
void			copy_index_to_norm_index(t_stack *stack_copied);
void			preprocess_radix_sort_base4(t_stack *stack);

/* push_swap_sort.c */
void			radix_base3(t_stack *s_from, t_stack *s_to, int num_op);
int				num_operation(int size);
void			three_sort_a(t_stack *stack_a);
void			three_sort_b(t_stack *stack_b);
void			mini_sort(t_stack *stack_a, t_stack *stack_b);

/* push_swap_sort2.c */
void			radix_base4_helper(t_stack *s_from,
					t_stack *s_to, t_stack_node *cur);
void			radix_base4(t_stack *s_from, t_stack *s_to, int num_op);
void			sort_under_108(t_stack *stack_a, t_stack *stack_b);
void			sort_normal(t_stack *stack_a, t_stack *stack_b);
void			sort_stack(t_stack *stack_a, t_stack *stack_b);

/* push_swap_stack.c */
t_stack_node	*create_node(int num);
void			enqueue(t_stack_node *new_node, t_stack *list);
t_stack_node	*dequeue(t_stack *list);
void			rotate_stack(t_stack *list);
void			reverse_rotate_stack(t_stack *list);

/* push_swap_stack2.c */
void			swap_top_two(t_stack *stack);
void			print_swap(t_stack *stack);
void			swap_top(t_stack *list);
void			push_stack(t_stack *list_from, t_stack *list_to);;
void			stack_a_init(t_stack *stack_a, int *normalized_list, int size);

/* push_swap_stack3.c */
void			push_b_to_a(t_stack *stack_a, t_stack *stack_b);

/* push_swap_utils.c */
void			ft_2d_free(void **mem, int size);
void			ft_safe_atoi_helper(const char **str, int *flag, long *num);
int				ft_safe_atoi(const char *str);
int				count_words(char **list);
void			throw_error(void);

/* push_swap_utils2.c */
void			free_list(t_stack *list);
t_stack			*copy_stack(t_stack *stack);
int				is_increasing(t_stack *stack);
void			free_node_list(t_index_node **sorted_list, int size);

#endif