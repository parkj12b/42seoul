/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:47:32 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/25 22:49:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "macros.h"
#include "utils.h"
#include "test_modules.h"

int	main(void)
{
	TEST_BEGIN;
	
	// Testing for executability in unaligned memory setting
	void *page = mmap(NULL, TEST_LEN, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);   
	
	for (size_t i = 0; i < TEST_LEN; i++) {
		((char *)page)[i] = 'a';
	}
	((char *)page)[TEST_LEN - 1] = '\0';

	test_module_ft_strlen(page);
	test_module_ft_strcpy();
	return (0);
}