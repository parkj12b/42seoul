/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:00:59 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 16:28:42 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlmalloc.h"
#include "utils.h"

t_malloc_info   info;

__attribute__((constructor))
static void init_malloc_library(void) {
    init_malloc_info(&info);
}