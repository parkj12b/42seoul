/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:22:17 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/12 16:58:45 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "dlmchunk.h"
#include "dlmalloc.h"
#include "globals.h"

void print_stack_trace(void) {
    void *buffer[64];
    int nptrs = backtrace(buffer, 64);
    fprintf(stderr, "Stack trace (%d frames):\n", nptrs);
    backtrace_symbols_fd(buffer, nptrs, 2);
}

void	log_hex(unsigned long n, int fd)
{
	char	hex[] = "0123456789abcdef";
	char	buf[16];
	int		i = 0;

	if (n == 0)
	{
		write(fd, "0x0", 3);
		return;
	}
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	write(fd, "0x", 2);
	while (i--)
		write(fd, &buf[i], 1);
}

void	log_ptr(void *ptr)
{
	log_hex((uintptr_t)ptr, 2);  // write to stderr
	write(2, "\n", 1);
}

void	print_chunk(void *chunk)
{
	t_mchunk	*ptr = (t_mchunk *)chunk;
	size_t		size = chunk_size(ptr);
	size_t		prev_size = ptr->prev_size;
	size_t		prev_inuse_ = prev_inuse(ptr);

	write(2, "------------\n", 12);
	write(2, "Chunk at: ", 10);
	log_ptr(chunk);
	write(2, "Prev size: ", 11);
	log_hex(prev_size, 2);
	write(2, "\nSize: ", 7);
	log_hex(size, 2);
	write(2, "\nPrev inuse: ", 13);
	if (prev_inuse_)
		write(2, "true", 4);
	else
		write(2, "false", 5);
	write(2, "------------\n", 12);
	write(2, "\n", 1);
}

void	print_heap() {
	t_mchunk *chunk = info.heap_start;

	while (is_valid_heap(chunk)) {
		print_chunk(chunk);
		write(2, "bk: ", 4);
		log_ptr(chunk->free_data.bk);
		write(2, "\nfd: ", 5);
		log_ptr(chunk->free_data.fd);
		write(2, "\n", 1);
		chunk = chunk->free_data.fd;
		// chunk = next_chunk(chunk);
	}
}

#include <unistd.h>
#include <stddef.h>  // for size_t

void reverse(char *str, int len) {
    int i = 0, j = len - 1;
    char tmp;
    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    }
}

void print_size_t(size_t num) {
    char buf[21];  // Enough for max 64-bit size_t (20 digits) + safety
    int i = 0;

    if (num == 0) {
        write(2, "0", 1);
        return;
    }

    while (num > 0) {
        buf[i++] = '0' + (num % 10);
        num /= 10;
    }

    reverse(buf, i);
    write(2, buf, i);
}

void	print_free_list() {
	for (int i = 0; i < 32; i++) {
		t_mchunk *cur = info.bins[i].free_data.fd;
		if (cur == &info.bins[i])
			continue ;
		write(2, "Bin ", 4);
		print_size_t(i);
		write(2, "\n", 1);
		while (cur != &info.bins[i]) {
			print_chunk(cur);
			cur = cur->free_data.fd;
		}
		write(2, "\n", 1);
	}
}
