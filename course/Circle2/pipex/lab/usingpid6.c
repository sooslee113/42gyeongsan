#include <stdio.h>
#include <unistd.h>

void foo()
{
    printf("execute foo\n");
}
void bar()
{
    printf("execute bar\n");
}
void zid()
{
    printf("execute zid\n");
}
int main()
{
    if (fork() == 0){
        if (fork() == 0){
            foo();
        }
        else{
            bar();
        }
    }
    else{
        zid();
    }
    return 0;
}