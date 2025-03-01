/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:08:53 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/01 22:12:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"
#include <stdio.h>

void    test_ft_create_elem()
{
    // Test 1: Basic creation with valid data
    int test_data1 = 42;
    t_list *node1 = ft_create_elem(&test_data1);
    assert(node1 != NULL);                  // Check allocation succeeded
    assert(node1->data == &test_data1);     // Check data field
    assert(node1->next == NULL);            // Check next field
    free(node1);                            // Clean up

    // Test 2: NULL data pointer
    t_list *node2 = ft_create_elem(NULL);
    assert(node2 != NULL);                  // Check allocation succeeded
    assert(node2->data == NULL);            // Check data field is NULL
    assert(node2->next == NULL);            // Check next field
    free(node2);

    // Test 3: Large data pointer
    char large_data[1024] = "Large data test";
    t_list *node3 = ft_create_elem(large_data);
    assert(node3 != NULL);                  // Check allocation succeeded
    assert(node3->data == large_data);      // Check data field
    assert(node3->next == NULL);            // Check next field
    free(node3);

    // Test 4: Multiple creations
    int test_data4a = 1, test_data4b = 2;
    t_list *node4a = ft_create_elem(&test_data4a);
    t_list *node4b = ft_create_elem(&test_data4b);
    assert(node4a != NULL && node4b != NULL);       // Check both allocated
    assert(node4a->data == &test_data4a);           // Check first node data
    assert(node4b->data == &test_data4b);           // Check second node data
    assert(node4a->next == NULL && node4b->next == NULL); // Check next fields
    assert(node4a != node4b);                       // Check distinct nodes
    free(node4a);
    free(node4b);

    TEST_SUCCESS;
}