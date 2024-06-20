#include <stdio.h>
#include <unistd.h>

//자식 프로세스 생성하기

int main()
{
    printf("parent pid is %d\n", getpid());

    if(fork() == 0) // fork()는 자식 프로세스를 생성한다. fork()의 결과로 반환되는 값이 0인 프로세스는 자식 프로세스, fork()의 결과로 반환되는 값이 자식프로세스의 PID인 프로세스는 부모프로세스 입니다.
    {
        printf("fork의 값 %d\n", fork());
        printf("child pid is %d\n",getpid()); 
    }
    return 0;
}