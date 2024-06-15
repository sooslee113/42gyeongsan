#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main ()
{
    int fd;
    fd = open("./unexisted.txt", O_RDONLY);
    printf("%d\n", fd);
    printf("%d\n", errno);
    if (fd == -1)
        perror("File is not existed");
    return 0;
}