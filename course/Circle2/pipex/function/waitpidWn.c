#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;

    if ((pid = fork()) == -1)
        puts("fork 함수 에러!!\a\n");
    else if (pid != 0)
    {
        // 부모
        while (waitpid(pid, NULL, WNOHANG) == 0)
        {
            puts("부모프로세스 살아있지롱");
            sleep(1);
        }
    }
    else
    {
        //자식
        puts("자식 프로세스다");
        sleep(3);
        exit(0);
    }
    return 0;
}