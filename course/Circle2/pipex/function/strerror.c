#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main ()
{
    int fd;
    fd = open("./unexisted.txt", O_RDONLY);
    printf("fd의 값 : %d\n", fd);
    printf("errno 의 값: %d\n", errno);
    if (fd == -1)
        printf("파일이 없는 데요? : %s\n",strerror(errno));
    return 0;
}