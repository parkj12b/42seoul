/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:29:19 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/03 18:04:45 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"

int free_count;

// Custom free function that counts calls and frees memory
void test_free(void *ptr)
{
    free_count++;
    free(ptr);
}

// Build a list from an array of integers
t_list *build_list(int *values, int size)
{
    t_list *list = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        int *data = malloc(sizeof(int));
        *data = values[i];
        t_list *new = ft_create_elem(data);
        new->next = list;
        list = new;
    }
    return list;
}

// Check if the list matches expected values
void check_list(t_list *list, int *expected, int size)
{
    int i = 0;
    for (; list && i < size; i++)
    {
        assert(*(int *)(list->data) == expected[i]);
        list = list->next;
    }
    assert(i == size && list == NULL);
}

// Comparison function for integer equality
int cmp_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

// Comparison function to remove even numbers
int cmp_even(void *a, void *b)
{
    (void)b; // Unused
    return (*(int *)a % 2 == 0) ? 0 : 1;
}

// Test 1: Basic Removal
static void test_basic_removal()
{
    int values[] = {1, 2, 3, 4};
    t_list *list = build_list(values, 4);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1, 3, 4};
    check_list(list, expected, 3);
    assert(free_count == 1);
    ft_list_clear(list, free);
}

// Test 2: Empty List
static void test_empty_list()
{
    t_list *list = NULL;
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    assert(list == NULL);
    assert(free_count == 0);
}

// Test 3: All Elements Removed
static void test_all_removed()
{
    int values[] = {2, 2, 2};
    t_list *list = build_list(values, 3);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    assert(list == NULL);
    assert(free_count == 3);
}

// Test 4: No Elements Removed
static void test_no_removal()
{
    int values[] = {1, 3, 4};
    t_list *list = build_list(values, 3);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1, 3, 4};
    check_list(list, expected, 3);
    assert(free_count == 0);
    ft_list_clear(list, free);
}

// Test 5: Remove from Beginning
static void test_remove_from_beginning()
{
    int values[] = {2, 2, 1, 3};
    t_list *list = build_list(values, 4);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1, 3};
    check_list(list, expected, 2);
    assert(free_count == 2);
    ft_list_clear(list, free);
}

// Test 6: Remove from End
static void test_remove_from_end()
{
    int values[] = {1, 3, 2, 2};
    t_list *list = build_list(values, 4);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1, 3};
    check_list(list, expected, 2);
    assert(free_count == 2);
    ft_list_clear(list, free);
}

// Test 7: Remove Consecutive Elements
static void test_remove_consecutive()
{
    int values[] = {1, 2, 2, 3};
    t_list *list = build_list(values, 4);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1, 3};
    check_list(list, expected, 2);
    assert(free_count == 2);
    ft_list_clear(list, free);
}

// Test 8: Single Element Removed
static void test_one_element_removed()
{
    int values[] = {2};
    t_list *list = build_list(values, 1);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    assert(list == NULL);
    assert(free_count == 1);
}

// Test 9: Single Element Not Removed
static void test_one_element_not_removed()
{
    int values[] = {1};
    t_list *list = build_list(values, 1);
    int ref = 2;
    free_count = 0;
    ft_list_remove_if(&list, &ref, cmp_int, test_free);
    int expected[] = {1};
    check_list(list, expected, 1);
    assert(free_count == 0);
    ft_list_clear(list, free);
}

// Test 10: Custom Comparison (Remove Even Numbers)
static void test_custom_cmp()
{
    int values[] = {1, 2, 3, 4};
    t_list *list = build_list(values, 4);
    free_count = 0;
    ft_list_remove_if(&list, NULL, cmp_even, test_free);
    int expected[] = {1, 3};
    check_list(list, expected, 2);
    assert(free_count == 2);
    ft_list_clear(list, free);
}

// Main function to run all tests
void    test_module_ft_list_remove_if()
{
    test_basic_removal();
    test_empty_list();
    test_all_removed();
    test_no_removal();
    test_remove_from_beginning();
    test_remove_from_end();
    test_remove_consecutive();
    test_one_element_removed();
    test_one_element_not_removed();
    test_custom_cmp();
    TEST_SUCCESS;
}