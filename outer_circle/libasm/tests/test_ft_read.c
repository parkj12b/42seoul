#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "libasm.h"
#include "macros.h"

// Test 1: Read from a file
void test_read_file() {
    int fd = open("testfile.txt", O_RDWR | O_CREAT, 0644);
    assert(fd >= 0 && "Failed to open testfile");
    write(fd, "Hello", 5);
    lseek(fd, 0, SEEK_SET); // Rewind to start

    char buf[10] = {0};
    ssize_t ret = ft_read(fd, buf, 5);
    //"Test 1 - Read from file: ret = %zd, buf = '%s', errno = %d\n", ret, buf, errno
    assert(ret == 5 && "Expected 5 bytes read");
    assert(strcmp(buf, "Hello") == 0 && "Expected 'Hello'");
    assert(errno == 0 && "Expected no error");

    close(fd);
    remove("testfile.txt");
}

// Test 2: Read from invalid FD
void test_read_invalid_fd() {
    char buf[10];
    errno = 0;
    ssize_t ret = ft_read(-1, buf, 5);
    //"Test 2 - Invalid FD: ret = %zd, errno = %d (expecting EBADF = 9)\n", ret, errno
    assert(ret == -1 && "Expected -1");
    assert(errno == EBADF && "Expected EBADF (9)");
}

// Test 5: Read from stdin (blocking, manual input required)
void test_read_stdin_blocking() {
    errno = 0;
    char buf[10] = {0};
    printf("Enter up to 5 chars for stdin (then Enter): \n");
    ssize_t ret = ft_read(0, buf, 5);
    //"\nTest 5 - Read from stdin: ret = %zd, buf = '%s', errno = %d\n", ret, buf, errno
    assert(ret >= 0 && ret <= 5 && "Expected 0-5 bytes read");
    assert(errno == 0 && "Expected no error");
}

// Test 6: Read from stdin (non-blocking)
void test_read_stdin_nonblocking() {
    int flags = fcntl(0, F_GETFL, 0);
    fcntl(0, F_SETFL, flags | O_NONBLOCK); // Set stdin non-blocking

    char buf[10] = {0};
    errno = 0;
    ssize_t ret = ft_read(0, buf, 5);
    //"Test 6 - Non-blocking stdin: ret = %zd, errno = %d (expecting EAGAIN = 35)\n", ret, errno
    assert(ret == -1 && "Expected -1 if no input");
    assert(errno == EAGAIN && "Expected EAGAIN (35)");

    fcntl(0, F_SETFL, flags); // Restore blocking mode
}

void test_module_ft_read()
{
    errno = 0;
    test_read_file();
    test_read_invalid_fd();
    test_read_stdin_blocking();  // Requires manual input
    test_read_stdin_nonblocking();
    TEST_SUCCESS;
}
