/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:41:13 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/02 22:45:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "libasm_bonus.h"
#include "utils.h"

void    test_module_ft_list_sort(void)
{
    t_list *begin = ft_create_elem("1");
    t_list *clean = begin;
    begin->next = ft_create_elem("7");
    begin->next->next = ft_create_elem("2");
    begin->next->next->next = ft_create_elem("5");

	ft_list_sort(&begin, strcmp);
	int i = 0;
	while (begin)
	{
		i++;
		printf("current iteration: %d\n", i);
		printf("%s\n\n", begin->data);
		begin = begin->next;
	}
	ft_list_clear(clean, do_nothing);
}