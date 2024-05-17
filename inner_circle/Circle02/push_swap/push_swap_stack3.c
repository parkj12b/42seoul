/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 21:30:09 by minsepar          #+#    #+#             */
/*   Updated: 2023/12/31 22:13:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->head)
		push_stack(stack_b, stack_a);
}
