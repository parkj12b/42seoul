/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:47:32 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/23 19:59:18 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "macros.h"
#include "libasm.h"

void	timed_execution(func_ptr func)
{
	clock_t	start, end;
	double	time_spent;

	start = clock();
	func();
	end = clock();
	time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds\n\n", time_spent);
}

void	test_ft_strlen(void)
{
	static char	*str = "Hello, World!";
	char		*long_str = malloc(TEST_LEN + 1);

	for (int i = 0; i < TEST_LEN; i++)
		long_str[i] = 'a';
	long_str[TEST_LEN] = '\0';

	assert(ft_strlen(str) == strlen(str));
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen(long_str) == strlen(long_str));
	TEST_SUCCESS;
}

void	test_ft_strcpy(const char *restrict src)
{
	char	*dst1 = malloc(strlen(src) + 1);
	char	*dst2 = malloc(strlen(src) + 1);

	ft_strcpy(dst1, src);
	strcpy(dst2, src);
	assert(strcmp(dst1, dst2) == 0);
	free(dst1);
	free(dst2);
}

void	test_module_ft_strcpy(void)
{
	test_ft_strcpy("Hello, World!");
	test_ft_strcpy("bye bye");
	test_ft_strcpy("");
	test_ft_strcpy("42");

	TEST_SUCCESS;
}

void	test_ft_strcmp(void)
{
	
}

int	main(void)
{
	TEST_BEGIN;
	timed_execution(test_ft_strlen);
	test_module_ft_strcpy();
	test_ft_strcmp();
	return (0);
}