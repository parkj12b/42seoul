/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:00:08 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/27 21:35:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "libasm.h"
#include "macros.h"

static char *str = "hello";

static void    test_identical_str(void)
{
    assert(strcmp(str, str) == ft_strcmp(str, str));
    assert(strcmp("", "") == ft_strcmp("", ""));
}

static void    test_string_and_null(void)
{
    assert(ft_strcmp("", str) < 0);
    assert(ft_strcmp(str, "") > 0);
}

static void    test_identical_shorter_str(void)
{
    assert(ft_strcmp("he", "hee") < 0);
    assert(ft_strcmp("hee", "he") > 0);
}

static void    test_special_char(void)
{
    char *str1 = "a\nb";
    char *str2 = "a\tb";

    assert(strcmp(str1, str2) == ft_strcmp(str1, str2));
}

static void    test_case_sensitive(void)
{
    assert(ft_strcmp("Cat", "cat") < 0);
}

void    test_module_ft_strcmp(void)
{
    test_identical_str();
    test_string_and_null();
    test_identical_shorter_str();
    test_special_char();
    test_case_sensitive();
    TEST_SUCCESS;
}