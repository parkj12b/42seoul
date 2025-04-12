#include <stdio.h>
#include <assert.h>
#include "dlmchunk.h"
#include "globals.h"
#include "dldllist.h"
#include "bins.h"

void test_init_bin() {
	t_mchunk bin;
	init_bin(&bin);
	assert(bin.free_data.fd == &bin);
	assert(bin.free_data.bk == &bin);
	printf("test_init_bin passed\n");
}

void test_unlink_chunk() {
	t_mchunk bin, node1, node2;
	init_bin(&bin);
	node1.size = 100;
	node2.size = 200;
	insert_node(&bin, &node1);
	insert_node(&node1, &node2);

	unlink_chunk(&node1);
	assert(bin.free_data.fd == &node2);
	assert(node2.free_data.bk == &bin);
	printf("test_unlink_chunk passed\n");
}

void test_insert_node() {
	t_mchunk bin, node1, node2;
	init_bin(&bin);
	insert_node(&bin, &node1);
	insert_node(&node1, &node2);

	assert(bin.free_data.fd == &node1);
	assert(node1.free_data.fd == &node2);
	assert(node2.free_data.bk == &node1);
	assert(node1.free_data.bk == &bin);
	printf("test_insert_node passed\n");
}

void test_insert_sorted() {
	t_mchunk bin, node1, node2, node3;
	init_bin(&bin);

	node1.size = 50;
	node2.size = 30;
	node3.size = 40;

	insert_sorted(&bin, &node1);
	insert_sorted(&bin, &node2);
	insert_sorted(&bin, &node3);

	assert(bin.free_data.fd == &node1);
	assert(node1.free_data.fd == &node3);
	assert(node3.free_data.fd == &node2);
	assert(node2.free_data.fd == &bin);
	printf("test_insert_sorted passed\n");
}
