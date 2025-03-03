#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"
#include "utils.h"

// Test Case 1: Empty List
static void test_empty_list(void)
{
    t_list *begin = NULL;
    PRINT(printf("Testing empty list:\n"););
    ft_list_sort(&begin, strcmp);
    if (begin == NULL)
	{
        PRINT(printf("List is still NULL (correct)\n\n"););
	}
    else
	{
        PRINT(printf("Error: List should be NULL\n\n"););
	}
}

// Test Case 2: Single Element
static void test_single_element(void)
{
    t_list *begin = ft_create_elem("42");

    PRINT(printf("Testing single element:\n"););
    ft_list_sort(&begin, strcmp);
    PRINT(printf("Element: %s\n\n", (char *)begin->data););
    ft_list_clear(begin, do_nothing);
}

// Test Case 3: Two Elements (Already Sorted)
static void test_two_sorted(void)
{
    t_list *begin = ft_create_elem("1");
    begin->next = ft_create_elem("2");
    PRINT(printf("Testing two sorted elements:\n"););
    ft_list_sort(&begin, strcmp);
    t_list *temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("%s\n", (char *)temp->data););
        temp = temp->next;
    }
    PRINT(printf("\n"););
    ft_list_clear(begin, do_nothing);
}

// Test Case 4: Two Elements (Reverse Order)
static void test_two_reverse(void)
{
    t_list *begin = ft_create_elem("2");
    begin->next = ft_create_elem("1");
    PRINT(printf("Testing two reverse elements:\n"););
    ft_list_sort(&begin, strcmp);
    t_list *temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("%s\n", (char *)temp->data););
        assert(('0' + i) == (int)(*(char *)temp->data));
        temp = temp->next;
    }
    PRINT(printf("\n"););
    ft_list_clear(begin, do_nothing);
}

// Test Case 5: All Equal Elements
static void test_all_equal(void)
{
    t_list *begin = ft_create_elem("5");
    begin->next = ft_create_elem("5");
    begin->next->next = ft_create_elem("5");
    PRINT(printf("Testing all equal elements:\n"););
    ft_list_sort(&begin, strcmp);
    t_list *temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("Node %d: %s\n", i, (char *)temp->data););
        assert(('0' + 5) == (int)(*(char *)temp->data));
        temp = temp->next;
    }
    PRINT(printf("\n"););
    ft_list_clear(begin, do_nothing);
}

// Original Test Case: Random Order (5 elements)
static void test_random_order(void)
{
    t_list *begin = ft_create_elem("2");
    begin->next = ft_create_elem("1");
    begin->next->next = ft_create_elem("7");
    begin->next->next->next = ft_create_elem("3");
    begin->next->next->next->next = ft_create_elem("9");
    PRINT(printf("Testing random order list:\n"););
    ft_list_sort(&begin, strcmp);
    t_list *temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("current iteration: %d\n", i););
        PRINT(printf("%s\n\n", (char *)temp->data););
        temp = temp->next;
    }
    ft_list_clear(begin, do_nothing);
}

// Test Case 6: Large Sorted List
static void test_large_sorted(void)
{
    t_list *begin = ft_create_elem(strdup("1"));
    t_list *temp = begin;
    for (int i = 2; i <= 9; i++)
    {
        char str[3];
        PRINT(sprintf(str, "%d", i););
        temp->next = ft_create_elem(strdup(str));
        temp = temp->next;
    }
    PRINT(printf("Testing large sorted list:\n"););
    ft_list_sort(&begin, strcmp);
    temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("Node %d: %s\n", i, (char *)temp->data););
        assert(('0' + i) == (int)(*(char *)temp->data));
        temp = temp->next;
    }
    PRINT(printf("\n"););
    ft_list_clear(begin, free);
}

// Test Case 7: Large Reverse Order
static void test_large_reverse(void)
{
    t_list *begin = ft_create_elem(strdup("9"));
    t_list *temp = begin;
    for (int i = 8; i >= 1; i--)
    {
        char str[3];
        PRINT(sprintf(str, "%d", i););
        temp->next = ft_create_elem(strdup(str));
        temp = temp->next;
    }
    PRINT(printf("Testing large reverse list:\n"););
    ft_list_sort(&begin, strcmp);
    temp = begin;
    int i = 0;
    while (temp)
    {
        i++;
        PRINT(printf("Node %d: %s\n", i, (char *)temp->data););
        assert(('0' + i) == (int)(*(char *)temp->data));
        temp = temp->next;
    }
    PRINT(printf("\n"););
    ft_list_clear(begin, free);
}

// Main function to run all tests
void	test_module_ft_list_sort(void)
{
    test_empty_list();
    test_single_element();
    test_two_sorted();
    test_two_reverse();
    test_all_equal();
    test_random_order();
    test_large_sorted();
    test_large_reverse();
	TEST_SUCCESS;
}