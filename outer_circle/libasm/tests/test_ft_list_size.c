/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:30:31 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/02 22:40:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"
#include "utils.h"

void    test_module_ft_list_size(void)
{
    // Test 1: NULL
    assert(ft_list_size(NULL) == 0);

    // Test 2: Single node
    t_list *list2 = ft_create_elem(NULL);
    assert(ft_list_size(list2) == 1);

    // Test 3: Larger list (5 nodes)
    t_list *list4 = ft_create_elem(NULL);
    list4->next = ft_create_elem(NULL);
    list4->next->next = ft_create_elem(NULL);
    list4->next->next->next = ft_create_elem(NULL);
    list4->next->next->next->next = ft_create_elem(NULL);
    assert(ft_list_size(list4) == 5);

    // Clean up
    ft_list_clear(list2, do_nothing);
    ft_list_clear(list4, do_nothing);
    TEST_SUCCESS;
}