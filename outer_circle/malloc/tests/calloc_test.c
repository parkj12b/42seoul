#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>
#include <unistd.h>
#include "globals.h"
#include "utils.h"
#include "dlmalloc.h"
#include "dlmchunk.h"
#include "log.h"
#include "macros.h"
#include "dldllist.h"
#include "test.h"

// Helper function to check if memory is zeroed
static int is_zeroed(void *ptr, size_t size) {
    unsigned char *bytes = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        if (bytes[i] != 0) {
            return 0;
        }
    }
    return 1;
}

// Helper function to check alignment
static int is_aligned(void *ptr, size_t alignment) {
    return ((uintptr_t)ptr % alignment) == 0;
}

// Test basic calloc functionality
void test_basic_calloc() {
    write(2, "Running test_basic_calloc...\n", 29);
    reset_heap();
    
    // Test allocation and zero initialization
    size_t test_sizes[] = {1, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    
    for (size_t i = 0; i < sizeof(test_sizes) / sizeof(test_sizes[0]); i++) {
        size_t size = test_sizes[i];
        void *ptr = calloc(1, size);
        
        // Verify allocation succeeded
        assert(ptr != NULL);
        
        // Verify alignment
        assert(is_aligned(ptr, ALIGNMENT));
        
        // Verify memory is zeroed
        assert(is_zeroed(ptr, size));
        
        // Write to memory to ensure it's usable
        memset(ptr, 0xAA, size);
        
        // Verify we can read back what we wrote
        unsigned char *mem = (unsigned char *)ptr;
        for (size_t j = 0; j < size; j++) {
            assert(mem[j] == 0xAA);
        }
        
        free(ptr);
    }
    
    write(2, "test_basic_calloc passed!\n", 27);
}

// Test calloc with various element counts
void test_calloc_count() {
    write(2, "Running test_calloc_count...\n", 29);
    reset_heap();
    
    // Test with various counts
    size_t counts[] = {1, 2, 10, 100, 1000};
    size_t elem_size = 4; // 4 bytes per element
    
    for (size_t i = 0; i < sizeof(counts) / sizeof(counts[0]); i++) {
        size_t count = counts[i];
        void *ptr = calloc(count, elem_size);
        
        // Verify allocation succeeded
        assert(ptr != NULL);
        
        // Verify memory is zeroed
        assert(is_zeroed(ptr, count * elem_size));
        
        // Write to first and last element
        unsigned char *mem = (unsigned char *)ptr;
        mem[0] = 0xBB;
        mem[(count * elem_size) - 1] = 0xBB;
        
        // Verify first and last element
        assert(mem[0] == 0xBB);
        assert(mem[(count * elem_size) - 1] == 0xBB);
        
        // Middle should still be zero
        if (count > 2) {
            assert(mem[elem_size] == 0);
            assert(mem[(count * elem_size) / 2] == 0);
        }
        
        free(ptr);
    }
    
    write(2, "test_calloc_count passed!\n", 27);
}

// Test edge cases
void test_calloc_edge_cases() {
    write(2, "Running test_calloc_edge_cases...\n", 34);
    reset_heap();
    
    // Test calloc(0, x)
    void *ptr1 = calloc(0, 10);
    assert(ptr1 == NULL);
    
    // Test calloc(x, 0)
    void *ptr2 = calloc(10, 0);
    assert(ptr2 == NULL);
    
    // Test calloc(0, 0)
    void *ptr3 = calloc(0, 0);
    assert(ptr3 == NULL);
    
    // Test with odd sizes
    void *ptr4 = calloc(3, 7);
    assert(ptr4 != NULL);
    assert(is_zeroed(ptr4, 3 * 7));
    free(ptr4);
    
    // Test with a small size
    void *ptr5 = calloc(1, 1);
    assert(ptr5 != NULL);
    assert(is_zeroed(ptr5, 1));
    free(ptr5);
    
    write(2, "test_calloc_edge_cases passed!\n", 32);
}

// Test calloc followed by free
void test_calloc_free_cycle() {
    write(2, "Running test_calloc_free_cycle...\n", 34);
    reset_heap();
    
    for (int i = 0; i < 100; i++) {
        size_t size = (i % 10) * 8 + 8; // 8 to 80 bytes
        void *ptr = calloc(i + 1, size);
        assert(ptr != NULL);
        assert(is_zeroed(ptr, (i + 1) * size));
        free(ptr);
    }
    
    write(2, "test_calloc_free_cycle passed!\n", 32);
}

// Test array allocation with calloc
void test_calloc_array() {
    write(2, "Running test_calloc_array...\n", 29);
    reset_heap();
    
    // Allocate an array of ints
    int *int_array = (int *)calloc(10, sizeof(int));
    assert(int_array != NULL);
    
    // Verify all elements are zero
    for (int i = 0; i < 10; i++) {
        assert(int_array[i] == 0);
    }
    
    // Write values
    for (int i = 0; i < 10; i++) {
        int_array[i] = i * 100;
    }
    
    // Verify values
    for (int i = 0; i < 10; i++) {
        assert(int_array[i] == i * 100);
    }
    
    free(int_array);
    
    // Allocate an array of structs
    typedef struct {
        int id;
        char name[16];
        double value;
    } TestStruct;
    
    TestStruct *struct_array = (TestStruct *)calloc(5, sizeof(TestStruct));
    assert(struct_array != NULL);
    
    // Verify all fields are zero
    for (int i = 0; i < 5; i++) {
        assert(struct_array[i].id == 0);
        assert(is_zeroed(struct_array[i].name, 16));
        assert(struct_array[i].value == 0.0);
    }
    
    // Initialize structs
    for (int i = 0; i < 5; i++) {
        struct_array[i].id = i + 1;
        sprintf(struct_array[i].name, "Item %d", i);
        struct_array[i].value = i * 1.5;
    }
    
    // Verify values
    for (int i = 0; i < 5; i++) {
        assert(struct_array[i].id == i + 1);
        assert(strcmp(struct_array[i].name, "") != 0);
        assert(struct_array[i].value == i * 1.5);
    }
    
    free(struct_array);
    
    write(2, "test_calloc_array passed!\n", 27);
}

// Run all calloc tests
void test_calloc() {
    write(2, "\n=== CALLOC TESTS ===\n", 22);
    
    test_basic_calloc();
    test_calloc_count();
    test_calloc_edge_cases();
    test_calloc_free_cycle();
    test_calloc_array();
    
    write(2, "All calloc tests passed!\n", 25);
}