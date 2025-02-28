/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:47:32 by minsepar          #+#    #+#             */
/*   Updated: 2025/02/28 22:26:20 by minsepar         ###   ########.fr       */
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

#include "libasm.h"
#include <errno.h>
#include <fcntl.h>

int	main(void)
{
	TEST_BEGIN;
	
	// Testing for executability in unaligned memory setting
	void *page = mmap(NULL, TEST_LEN, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);   
	
	for (size_t i = 0; i < TEST_LEN; i++) {
		((char *)page)[i] = 'a';
	}
	((char *)page)[TEST_LEN - 1] = '\0';

	test_module_ft_strlen((page + 4094));
	test_module_ft_strcpy();
	test_module_ft_strcmp();
	test_module_ft_write();
	test_module_ft_read();
	test_ft_isspace();

	ft_atoi_base("    abc", "0");

	return (0);
}