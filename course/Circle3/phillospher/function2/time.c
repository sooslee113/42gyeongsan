#include "test.h"

// struct timeval
// {
//     time_t  tv_sec;
//     suseconds_t tv_usec;
// };

uint64_t get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return(0);

    return (tv.tv_sec * (uint64_t)1000 + (tv.tv_usec / 1000));
}
void    example_1()
{
    struct timeval time;

    if (gettimeofday(&time, NULL))
        return;
    printf("%ld seconds\n", time.tv_sec);
    printf("%ld seconds\n", time.tv_usec);
    printf("%ld years passed since 1970\n\n", time.tv_sec / 60 / 60 / 24 / 365);
    
}

void example_2()
{
    uint64_t start_time;
    uint64_t now;

    start_time = get_time();
    usleep(10000);
    now = get_time();
    printf("%ld milliseconds passed since the start\n", now - start_time);
}

int main()
{
    example_1();
    example_2();
}