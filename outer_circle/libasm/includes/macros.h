/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:49:48 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/25 22:43:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

#include <stdio.h>

typedef void (*func_ptr)(void *arg);

# define GREEN "\033[32m"
# define RESET "\033[0m"

# define TEST_LEN 10000000 //100,000,000

# define TEST_BEGIN fprintf(stderr, "Running tests...\n")
# define TEST_FN fprintf(stderr, "Testing %s \n", __func__)
# define TEST_SUCCESS fprintf(stderr, "%s: " GREEN "OK" RESET "\n", __func__)

#endif