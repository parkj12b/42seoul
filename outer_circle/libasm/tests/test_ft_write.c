#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "macros.h"
#include "libasm.h"


// Test 1: Writing to a valid file descriptor (stdout)
void test_write_stdout() {
    const char *buf = "Hello, stdout!\n";
    size_t count = strlen(buf);
    ssize_t ret = ft_write(1, buf, count); // stdout = 1
    //"Test 1 - Write to stdout: ret = %zd, errno = %d\n", ret, errno
    assert(ret == (ssize_t)count && "Expected full write to stdout");
    assert(errno == 0 && "errno should be 0 on success");
}

// Test 2: Writing to an invalid file descriptor
void test_write_invalid_fd() {
    errno = 0; // Reset errno
    ssize_t ret = ft_write(-1, "test", 4);
    //"Test 2 - Invalid FD: ret = %zd, errno = %d (expecting EBADF = 9)\n", ret, errno
    assert(ret == -1 && "Expected -1 on invalid fd");
    assert(errno == EBADF && "Expected EBADF (9)");
}

// Test 3: Writing with a NULL buffer (EFAULT)
void test_write_null_buffer() {
    int fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open testfile");
        exit(1);
    }
    errno = 0;
    ssize_t ret = ft_write(fd, NULL, 4);
    //"Test 3 - NULL buffer: ret = %zd, errno = %d (expecting EFAULT = 14)\n", ret, errno
    assert(ret == -1 && "Expected -1 on NULL buffer");
    assert(errno == EFAULT && "Expected EFAULT (14)");
    close(fd);
    remove("testfile.txt");
}

// Test 4: Writing zero bytes
void test_write_zero_bytes() {
    errno = 0;
    ssize_t ret = ft_write(1, "test", 0);
    //"Test 4 - Zero bytes: ret = %zd, errno = %d\n", ret, errno
    assert(ret == 0 && "Expected 0 when count = 0");
    assert(errno == 0 && "errno should be 0");
}

// Test 5: Writing to a read-only file
void test_write_readonly() {
    int fd = open("readonly.txt", O_RDONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open readonly file");
        exit(1);
    }
    errno = 0;
    ssize_t ret = ft_write(fd, "test", 4);
    //"Test 5 - Read-only FD: ret = %zd, errno = %d (expecting EBADF = 9)\n", ret, errno
    assert(ret == -1 && "Expected -1 on read-only fd");
    assert(errno == EBADF && "Expected EBADF (9)");
    close(fd);
    remove("readonly.txt");
}

void test_module_ft_write()
{
    errno = 0;
    test_write_stdout();
    test_write_invalid_fd();
    test_write_null_buffer();
    test_write_zero_bytes();
    test_write_readonly();
    TEST_SUCCESS;
}
