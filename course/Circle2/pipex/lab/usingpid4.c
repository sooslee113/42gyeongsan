#include <stdio.h>
#include <unistd.h>

void foo()
{
    printf("execute foo\n");
}


int main()
{
    if (fork() == 0)
    {
        printf("child pid is %d\n", getpid());
        foo();
    }
    else 
    {
        printf("parent pid is %d\n", getpid());
        foo();
    }
    return 0;
    // fork가 된 순간 동일한 코드를 실행하는 자식 프로세스가 생성된다.
}