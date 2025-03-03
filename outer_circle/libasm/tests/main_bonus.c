/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:47:32 by minsepar          #+#    #+#             */
/*   Updated: 2025/03/03 17:41:41 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "macros.h"
#include "test_modules.h"
#include "libasm_bonus.h"
#include "utils.h"


#include <string.h>

void    leaks()
{
    system("leaks a.out");
}

int	main(void)
{
    atexit(leaks);
	TEST_BEGIN;
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
    
	// Testing for executability in unaligned memory setting
	test_ft_isspace();
	test_module_ft_atoi_base();
	test_ft_create_elem();
    test_module_ft_list_push_front();
	test_module_ft_list_size();
	test_module_ft_list_sort();
	test_module_ft_list_remove_if();

	return (0);
}