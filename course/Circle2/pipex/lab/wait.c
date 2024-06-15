#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid;
    int status;


    pid = fork();// 복사된 프로세스의 수행시점은 이곳이 된다. 

    if (pid == 0)
    {
        printf("*******자식 프로세스***********\n");
        sleep(4);
        printf("*******자식 프로세스 종료***********\n");
    }
    else
    {
        int wait_prd = waitpid(pid, &status, WNOHANG);
        printf("*******부모 프로세스***********\n");
        sleep(2);
        printf("*******부모 프로세스 종료***********\n");
        printf("\nwaitpid 인자값 : %d\n waitpid 반환값: %d\n", status, wait_prd);
        printf("자식pid: %d\n", pid);
    }
    //printf("my pid is : %d\n", getpid());
    // "WNOHANG" 옵션은 자식 프로세스가 종료될 때까지 대기하지 않고 즉시 반환하라는 것을 의미합니다. 
    //따라서 부모 프로세스는 자식 프로세스가 종료될 때까지 대기하지 않고 바로 종료 메시지를 출력한 후, 
    //자식 프로세스의 종료 상태와 "waitpid" 함수의 반환값을 출력합니다.
    return 0;
}