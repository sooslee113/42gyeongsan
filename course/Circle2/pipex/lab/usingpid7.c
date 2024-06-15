#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid;

    pid = fork();// 복사된 프로세스의 수행시점은 이곳이 된다. 

    if (pid == 0)
    {
        printf("*******자식 프로세스***********\n");
        sleep(2);
        printf("child process : %d\n", pid);
    }
    else
    {
        printf("parent pid : %d\n", pid);
    }
    printf("my pid is : %d\n", getpid());
}