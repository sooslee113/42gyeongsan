#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fd1, fd2;
    char message[32]={"message via fd2\n"};

    fd1 = open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(fd1 < 0)
    {
        printf("%s\n", strerror(errno));
        return 1;
    }
    fd2 = dup(fd1);
    //printf("%d\n", fd2);
    write(fd2,message,strlen(message));
    write(fd1, "hello world\n", 13);
    printf("fd1 :%d, fd2:%d\n",fd1,fd2);
    close(fd1);
    close(fd2);
    return 0;
}
