#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
    int fd;
    fd = open("unlinktest.txt", O_RDONLY);
    if (unlink("unlinktest.txt") != 0)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        printf("unlink의 반환 값 : %d\n", unlink("unlinktest.txt"));
        printf("delete is complete");
    }
    return 0;
}