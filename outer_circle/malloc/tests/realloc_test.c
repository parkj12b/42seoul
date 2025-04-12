#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include "test.h"
#include "globals.h"
#include "utils.h"
#include "dlmalloc.h"
#include "dlmchunk.h"
#include "log.h"
#include "macros.h"
#include "dldllist.h"

static void log_msg(const char *msg) {
    write(1, msg, strlen(msg));
}

// Test basic realloc functionality
void test_basic_realloc() {
    log_msg("Running test_basic_realloc...\n");
    reset_heap();
    
    // Test 1: NULL pointer should behave like malloc
    void *ptr1 = realloc(NULL, 64);
    assert(ptr1 != NULL);

    // Write some data to verify memory is usable
    memset(ptr1, 0xAA, 64);
    
    // Test 2: Grow the allocation
    void *ptr2 = realloc(ptr1, 128);
    assert(ptr2 != NULL);
    
    // Verify data was properly copied
    unsigned char *mem = (unsigned char *)ptr2;
    for (int i = 0; i < 64; i++) {
        assert(mem[i] == 0xAA);
    }
    
    // Write to the extended region
    memset(mem + 64, 0xBB, 64);
    
    // Test 3: Shrink the allocation
    void *ptr3 = realloc(ptr2, 32);
    assert(ptr3 != NULL);
    
    // Verify data was properly copied
    mem = (unsigned char *)ptr3;
    for (int i = 0; i < 32; i++) {
        assert(mem[i] == 0xAA);
    }
    
    // Test 4: Zero size should free the pointer and return NULL
    void *ptr4 = realloc(ptr3, 0);
    assert(ptr4 == NULL);
    
    log_msg("test_basic_realloc passed!\n");
}
#include <stdio.h>
// Test realloc with different sizes
void test_realloc_sizes() {
    log_msg("Running test_realloc_sizes...\n");
    reset_heap();
    
    // Test array of sizes to realloc through
    size_t sizes[] = {
        8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096,
        HPAGE_SIZE - 32, HPAGE_SIZE, HPAGE_SIZE + 32
    };
    
    void *ptr = malloc(8);
    assert(ptr != NULL);
    
    // Fill with recognizable pattern
    memset(ptr, 0x42, 8);
    
    // Progressively realloc to larger sizes
    for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        void *new_ptr = realloc(ptr, sizes[i]);
        assert(new_ptr != NULL);
        
        // Use logging from log.c or write directly
        // char buffer[128];
        // int len = snprintf(buffer, sizeof(buffer), "ptr: %p, size: %zu\n", new_ptr, ((t_mchunk *)((char *)new_ptr - 16))->size);
        // write(1, buffer, len);
        
        // Check that original data is preserved
        unsigned char *mem = (unsigned char *)new_ptr;
        for (size_t j = 0; j < 8; j++) {
            assert(mem[j] == 0x42);
        }
        
        // Fill the rest with a new pattern
        if (i < 4)
            memset(mem + 8, 0x43 + i, sizes[i] - 8);
        else
            memset(mem + 16, 0x44 + i, sizes[i] - 16);
        ptr = new_ptr;
    }
    
    // Now shrink back down
    for (int i = sizeof(sizes) / sizeof(sizes[0]) - 2; i >= 0; i--) {
        void *new_ptr = realloc(ptr, sizes[i]);
        assert(new_ptr != NULL);
        
        // Verify original data is still there
        unsigned char *mem = (unsigned char *)new_ptr;
        for (size_t j = 0; j < 8; j++) {
            assert(mem[j] == 0x42);
        }
        
        ptr = new_ptr;
    }
    
    // Clean up
    free(ptr);
    
    log_msg("test_realloc_sizes passed!\n");
}

// Test realloc edge cases
void test_realloc_edge_cases() {
    log_msg("Running test_realloc_edge_cases...\n");
    reset_heap();
    
    // Edge case 1: realloc(NULL, 0)
    void *ptr = realloc(NULL, 0);
    (void)ptr;  // Suppress unused variable warning
    
    log_msg("test_realloc_edge_cases passed!\n");
}

// Main test function that runs all realloc tests
void test_realloc() {
    log_msg("\n=== REALLOC TESTS ===\n");
    
    test_basic_realloc();
    test_realloc_sizes();
    test_realloc_edge_cases();
    
    log_msg("All realloc tests passed!\n");
}