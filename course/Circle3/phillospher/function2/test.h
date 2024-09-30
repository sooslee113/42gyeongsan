#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct timeval_s
{
    long tv_sec;
    long tv_usec;

} timeval_t;

#endif