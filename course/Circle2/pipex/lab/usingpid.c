#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("hello, world\n");
    printf("my pid is %d",getpid());
    return 0;
}