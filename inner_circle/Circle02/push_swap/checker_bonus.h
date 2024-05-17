/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:02:11 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/06 20:19:51 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list_node
{
	int					index;
	int					cur_digit;
	int					normalized_index;
	int					original_index;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}	t_list_node;

typedef struct s_list
{
	int			size;
	t_list_node	*head;
	t_list_node	*last;
}	t_list;

typedef struct s_index_node
{
	int	value;
	int	original_index;
	int	sorted_index;
}	t_index_node;

t_list_node		*create_node(int num);
t_list_node		*dequeue(t_list *list);
void			enqueue(t_list_node *new_node, t_list *list);
void			rotate_stack(t_list *list);
void			reverse_rotate_stack(t_list *list);
int				check_sorted(int *normalized_list, int size);
int				partition(t_index_node **list, int low, int high);
int				*normalize_list(t_index_node **list, int size);
void			swap_index_node_value(t_index_node **list, int i, int j);
void			stack_a_init(t_list *stack_a, int *normalized_list, int size);
void			list_init(t_list *list);
void			free_node_list(t_index_node **sorted_list, int size);
void			quicksort_list(t_index_node **list, int low, int high);
void			check_duplicate(t_index_node **sorted_list, int size);
int				count_words(char **list);
void			throw_error(void);
void			alist_to_nodelist_helper(char **parsed_string,
					t_index_node **list, int *size);
void			ft_atoi_helper(const char **str, int *flag, long *num);
int				ft_atoi(const char *str);
t_index_node	**alist_to_nodelist(char **argv, int *size);
void			swap_top_two(t_list *stack);
void			swap_top(t_list *list);
void			push_stack(t_list *list_from, t_list *list_to);
void			swap_a_and_b(t_list *stack_a, t_list *stack_b);
void			rotate_a_and_b(t_list *stack_a, t_list *stack_b);
void			reverse_rotate_a_and_b(t_list *stack_a, t_list *stack_b);
void			free_list(t_list *list);
void			process_command_error(t_list *stack_a,
					t_list *stack_b, char *str);
void			process_command_helper(t_list *stack_a,
					t_list *stack_b, char *str);
void			process_command(t_list *stack_a, t_list *stack_b);
void			ft_2d_free(void **mem, int size);

/* libft */
void			*ft_calloc(size_t count, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
char			*get_next_line(int fd);

#endif