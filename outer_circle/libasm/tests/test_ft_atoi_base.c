/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:40:17 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/01 20:05:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libasm_bonus.h"
#include "macros.h"

void    test_module_ft_atoi_base(void)
{
    assert(ft_atoi_base("42", "0123456789") == 42);              // Basic Positive
    assert(ft_atoi_base("-42", "0123456789") == -42);            // Negative Number
    assert(ft_atoi_base("   123", "0123456789") == 123);        // Leading Whitespace
    assert(ft_atoi_base("+98", "0123456789") == 98);            // Positive Sign
    assert(ft_atoi_base("1a", "0123456789abcdef") == 26);       // Hexadecimal
    assert(ft_atoi_base("-ff", "0123456789abcdef") == -255);    // Negative Hex
    assert(ft_atoi_base("12x3", "0123456789") == 12);           // Invalid Digit
    assert(ft_atoi_base("", "0123456789") == 0);                // Empty String
    assert(ft_atoi_base("42", "") == 0);                        // Empty Base
    assert(ft_atoi_base("42", "0") == 0);                       // Base Length 1
    assert(ft_atoi_base("11", "01123456789") == 0);             // Duplicate in Base
    assert(ft_atoi_base("42", "01+3456789") == 0);              // Sign in Base
    assert(ft_atoi_base("42", "01 3456789") == 0);              // Whitespace in Base
    assert(ft_atoi_base("2147483647", "0123456789") == 2147483647); // Max Int
    assert(ft_atoi_base("2147483648", "0123456789") == -2147483648); // Overflow (wraps)
    TEST_SUCCESS;
}