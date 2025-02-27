/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:47:20 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/27 22:05:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include "libasm.h"
#include "test_modules.h"
#include "macros.h"
#include "utils.h"

static void test_strlen(void *arg) {
	(void) strlen(arg);
}

static void	test_ft_strlen(void *arg)
{
	ft_strlen(arg);
}

void	test_module_ft_strlen(void *arg)
{
	static char	*str = "Hello, World!";

	printf("ft_strlen:\n");
	timed_execution(test_ft_strlen, ((char *) arg + 1));
	printf("strlen:\n");
	timed_execution(test_strlen, ((char *) arg + 1));
	assert(ft_strlen(str) == strlen(str));
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen(arg) == strlen(arg));
	TEST_SUCCESS;
}
