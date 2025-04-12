/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:45:44 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/13 01:50:36 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "utils.h"
#include "log.h"

// Helper function to reset the heap state before each test
void reset_heap() {
    // printf("%p\n", info.heap_start);
    info.heap_start = NULL; 
    init_malloc_info();
    // print_heap();
    // printf("%p\n", info.heap_start);
    info.flags |= MALLOC_INIT;
}
