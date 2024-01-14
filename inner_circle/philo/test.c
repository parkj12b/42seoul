#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    struct timeval startTime, endTime;
    double diffTime;

    gettimeofday(&startTime, NULL);
    usleep(100000);
    gettimeofday(&endTime, NULL);
    diffTime = ( endTime.tv_sec - startTime.tv_sec ) + (( endTime.tv_usec - startTime.tv_usec ) / 1000000);
    printf("%f s\n", diffTime);
    return 0;
}