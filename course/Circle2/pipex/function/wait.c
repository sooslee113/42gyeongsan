#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pid, childPid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        //자식
        printf("자식 프로세스 출력\n");
        exit(5);
    }
    else
    {
        //부모
        printf("wait 쓰기 전 parent\n");
        childPid = wait(&status);
        printf("자식[pid : %d] 종료된 기록 : %x\n", childPid, status);
        
    }
}