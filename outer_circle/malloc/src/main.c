/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:10:01 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/06 21:02:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlmalloc.h"
#include "globals.h"

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
}