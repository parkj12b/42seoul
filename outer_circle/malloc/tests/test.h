#ifndef TEST_H
# define TEST_H

#include <stddef.h>

void test_init_bin();
void test_unlink_chunk();
void test_insert_node();
void test_insert_sorted();

/* init_test.c */

void test_init_heap_basic();
void test_init_heap_edge_case();
void test_all_chunks_in_bins();

#endif