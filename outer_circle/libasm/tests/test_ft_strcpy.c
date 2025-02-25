/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:47:17 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/25 22:47:40 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "libasm.h"
#include "macros.h"

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
