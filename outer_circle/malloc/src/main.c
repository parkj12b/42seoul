/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:10:01 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 23:38:54 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlmalloc.h"
#include "globals.h"

int circular_dll_len(t_mchunk *head) {
    t_mchunk    *cur = head->free_data.fd;
    int count = 0;

    while (cur != head) {
        count++;
        cur = cur->free_data.fd;
    }
    return count;
}

int main() {
    char *test1 = "hello";
    char *test2 = "i am";
    char *test3 = "jacob";

    char *str1 = ft_malloc(10);
    char *str2 = ft_malloc(10);
    char *str3 = ft_malloc(10);
    // char *str1 = malloc(10);
    // char *str2 = malloc(10);
    // char *str3 = malloc(10);

    strcpy(str1, test1);
    strcpy(str2, test2);
    strcpy(str3, test3);
    printf("%p\n", info.heap_start);
    printf("%p, %s\n%p, %s\n%p, %s\n", str1, str1, str2, str2, str3, str3);
    free(str1);
    free(str2);
    free(str3);
    
    // assert(circular_dll_len(&info.bins[0]) == 3);
}