#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 1000
int main()
{
    int fd1[2];
    //int fd2[2];
    char buffer[BUFSIZE];
    int pid;

    //fd[0] - read
    //fd[1] - write
    //fd[2] - error

    if(pipe(fd1) == -1)
    {
        printf("pipe error");
        exit(1);
    }

    pid = fork();

    if (pid == -1)
    {
        printf("fork() error");
        exit(1);
    }
    if (pid == 0)
    {
        write(fd1[1], "(자식에서 입력)\n", 25);
        read(fd1[0], buffer, 25);
        printf("\n자식출력: %s\n", buffer);
    }
    else
    {

    }
    return (0);
}