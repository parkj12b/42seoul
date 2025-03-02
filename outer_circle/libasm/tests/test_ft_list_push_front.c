/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:54:10 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/02 17:31:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"
#include "utils.h"

void    test_module_ft_list_push_front(void)
{
    t_list *list1 = NULL;
    int data1 = 42;
    ft_list_push_front(&list1, &data1);
    assert(list1 != NULL);                  // Check allocation
    printf("%d\n", *((int *)(list1->data)));
    assert(list1->data == &data1);          // Check data
    assert(list1->next == NULL);            // Check next
    ft_list_clear(list1, do_nothing);

    // Test 2: Push to non-empty list
    t_list *list2 = NULL;
    int data2a = 1, data2b = 2;
    ft_list_push_front(&list2, &data2a);   // First node
    ft_list_push_front(&list2, &data2b);   // Second node (front)
    assert(list2 != NULL);                  // Check head exists
    assert(list2->data == &data2b);         // Check new front data
    assert(list2->next != NULL);            // Check second node exists
    assert(list2->next->data == &data2a);   // Check original data
    assert(list2->next->next == NULL);      // Check end of list
    ft_list_clear(list2, do_nothing);

    // Test 3: Push NULL data
    t_list *list3 = NULL;
    ft_list_push_front(&list3, NULL);
    assert(list3 != NULL);                  // Check allocation
    assert(list3->data == NULL);            // Check data is NULL
    assert(list3->next == NULL);            // Check next
    ft_list_clear(list3, do_nothing);

    // Test 4: Multiple pushes
    t_list *list4 = NULL;
    int data4a = 1, data4b = 2, data4c = 3;
    ft_list_push_front(&list4, &data4a);
    ft_list_push_front(&list4, &data4b);
    ft_list_push_front(&list4, &data4c);
    assert(list4->data == &data4c);         // Check front
    assert(list4->next->data == &data4b);   // Check second
    assert(list4->next->next->data == &data4a); // Check third
    assert(list4->next->next->next == NULL); // Check end
    ft_list_clear(list4, do_nothing);
}