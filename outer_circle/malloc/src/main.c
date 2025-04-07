/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:10:01 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/07 18:24:25 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include "globals.h"

// int circular_dll_len(t_mchunk *head) {
//     t_mchunk    *cur = head->free_data.fd;
//     int count = 0;

//     while (cur != head) {
//         count++;
//         cur = cur->free_data.fd;
//     }
//     return count;
// }
#include <unistd.h>

void oneloop() {
    void *ptrs[10];
    for (int i = 0; i < 10; i++) {
        ptrs[i] = malloc(10 + 10 * i);
        for (int j = 0; j < 10 + 10 * i - 1; j++) {
            ((char *)ptrs[i])[j] = 'a' + i;
        }
        ((char *)ptrs[i])[10 + 10 * i - 1] = '\0';
        printf("ptrs[%d] = %p\n", i, ptrs[i]);
    }

    for (int i = 1; i < 10; i += 2) {
        free(ptrs[i]);
    }

    free(ptrs[4]);

    for (int i  = 0; i <10; i+= 2) {
        if (i == 4) continue;
        printf("address %p, str = %s\n", ptrs[i], ptrs[i]);
    }

    for (int i = 0; i < 10; i += 2) {
        if (i == 4) continue;
        free(ptrs[i]);
    }

    ptrs[0] = malloc(25);
    printf("ptr = %p\n", ptrs[0]);
    free(ptrs[0]);
}
int main() {
    char *test1 = "hello";
    char *test2 = "i am";
    char *test3 = "jacob";
    write(2, test1, strlen(test1)); // write to stderr
    // char *str1 = ft_malloc(10);
    // char *str2 = ft_malloc(10);
    // char *str3 = ft_malloc(10);
    char *str1 = malloc(10);
    char *str2 = malloc(10);
    char *str3 = malloc(10);

    strcpy(str1, test1);
    strcpy(str2, test2);
    strcpy(str3, test3);
    printf("%p: %s %p: %s %p: %s\n", str1, str1, str2, str2, str3, str3);
    free(NULL);
    str1 = realloc(str1, 2048);
    for (int i = 0; i < 2048; i++) {
        str1[i] = 'a';
    }
    printf("address: %p\nstr1: %s\n", str1, str1);

    void *ptr[10];
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(1 + 2 * i);
        printf("\n Iteration %d / 9 \n", i);
        oneloop();
    }

    for (int i = 0;  i< 10 ;i++) {
        free(ptr[i]);
    }

    // DLOG(printf("%p\n", info.heap_start);)
    // free(str1);
    // free(str2);
    // free(str3);
    
    // assert(circular_dll_len(&info.bins[0]) == 3);
}