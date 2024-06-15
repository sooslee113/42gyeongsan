#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid[3];
    printf("부모 pid : %d\n", getpid());
    if((pid[0] = fork()) == -1) // 
        puts("프로세스 생성 실패!\a\n\n");
    else if (pid[0] != 0)
    {
        waitpid(pid[2], NULL, WNOHANG);
        printf("첫 번째 자식 프로세스 : %d\n", pid[0]);
        pid[1] = fork();
        printf("두 번째 자식 프로세스! : %d\n", pid[1]);
        //exit(5);
        pid[2] = fork();
        printf("세 번째 자식 프로세스! : %d\n", pid[2]);
    }
    return 0;
}