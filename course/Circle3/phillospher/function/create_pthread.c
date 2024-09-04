#include "practice.h"
#include <unistd.h>

int g_data;
bool g_true = true;

//void * g_hThreadExit01, g_hThreadExit02;

void    *function1()
{
    // long thread_id = (long int) pthread_self();
    printf("This is function 1 - begin\n");
    // printf("PID is %d\n", getpid());
    // printf("This is thread %d\n", thread_id);
    while(g_true)
    {
        g_data = 1000;
    }
    printf("This is function 1 - end\n");
}

void    *function2()
{
    // long thread_id = (long int) pthread_self();
    printf("This is function 2 - begin\n");
    // printf("PID is %d\n", getpid());
    // printf("This is thread %d\n", thread_id);
    while(g_true)
    {
        g_data = 2000;
    }
    printf("This is function 2 - end\n");
}

void    *function3()
{
    // long thread_id = (long int) pthread_self();
    printf("This is function 3 - begin\n");
    // printf("PID is %d\n", getpid());
    // printf("This is thread %d\n", thread_id);
    for (int i = 0; i < 10; i++)
    {
        printf("This is function 3 : g_data = %d\n", g_data);
    }
    
    while(g_true)
    {
        g_data = 3000;
    }
    printf("This is function 3 - end\n");
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    printf("Hello World - begin\n");

    g_true = true;

    pthread_create(&thread1, NULL, function1, NULL);
    pthread_create(&thread2, NULL, function2, NULL);
    pthread_create(&thread3, NULL, function3, NULL);

    //호출자 스레드는 대기 상태로 전환된다.
    //sleep(3);
    sleep(3);
    g_true = false;
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
 
    printf("Hello World - end\n");
    return (0);
}