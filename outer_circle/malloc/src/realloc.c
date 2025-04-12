/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:03:16 by minsepar          #+#    #+#             */
/*   Updated: 2025/04/13 01:52:53 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "dlmchunk.h"
#include "macros.h"
#include "dlmalloc.h"
#include "utils.h"
#include "log.h"

int is_samepage(size_t new_size, size_t old_size) {
	if (align_page(new_size) == align_page(old_size))
		return 1;
	return 0;
}

void	*shrink_realloc(void *ptr, size_t new_size, size_t old_size) {
	t_mchunk	*return_chunk = NULL;
	t_mchunk	*chunk = (t_mchunk *)(ptr - HEADER_PADDING);
	size_t		aligned_size = ALIGN(new_size + HEADER_PADDING);
	size_t		delta = old_size - aligned_size;

	if (!is_valid_heap(chunk)) {
		if (is_samepage(aligned_size, old_size) && aligned_size > HPAGE_SIZE) {
			set_chunk_size(chunk, aligned_size);
			t_mchunk	*next = next_chunk(chunk);
			next->prev_size = chunk_size(chunk);
			return CHUNK_TO_USER(chunk);
		}
		void *return_ptr = malloc(new_size);
		memcpy(return_ptr, ptr, new_size);
		free(ptr);
		return return_ptr;
	}
	if (delta >= HEADER_PADDING) {
		return_chunk = split_chunk(chunk, aligned_size);
		t_mchunk	*next = next_chunk(return_chunk);
		next->prev_size = chunk_size(return_chunk);
		set_prev_inuse(next);
		return CHUNK_TO_USER(return_chunk);
	}
	return CHUNK_TO_USER(chunk);
}

void	*realloc(void *ptr, size_t size) {
	DLOG(write(2, "realloc called\n", 15);)
	if (ptr == NULL)
		return malloc(size);
	
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	t_mchunk	*chunk = (t_mchunk *)(ptr - HEADER_PADDING);
	size_t		old_size = chunk_size(chunk);
	size_t		aligned_size = ALIGN(size + HEADER_PADDING);

	if (aligned_size <= old_size)
		return shrink_realloc(ptr, size, old_size);
	
	if (!is_valid_heap(chunk) && is_samepage(aligned_size, old_size)) {
		set_chunk_size(chunk, aligned_size);
		return CHUNK_TO_USER(chunk);
	} 
	void	*new_ptr = malloc(size);
	if (new_ptr == NULL)
		return NULL;
	memcpy(new_ptr, ptr, old_size - HEADER_PADDING);
	free(ptr);
	return new_ptr;
}