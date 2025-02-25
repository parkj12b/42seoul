#include <string.h>
#include <stdlib.h>
#include "utils.h"

void test_strlen(void *arg)
{
    strlen(arg);
}

int main()
{

    char *str = malloc(TEST_LEN);

    for (int i = 0; i < TEST_LEN; i++)
    {
        str[i] = 'a';
    }
    str[TEST_LEN - 1] = '\0';


    timed_execution(test_strlen, str);
}