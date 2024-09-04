#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *t_function(void *ptr) { // 스레드에서 작업할 함수
        char *message;
        message = (char *)ptr;
        printf("%s start \n", message);
        sleep(5);
        printf("%s end\n", message);
        return 0;
}

int main() {
        pthread_t thread1, thread2; // 스레드 변수 생성
        const char *message1 = "Thread1";
        const char *message2 = "Thread2";
        int ret, status;

        ret = pthread_create(&thread1, NULL, t_function, (void *)message1); // 스레드 생성
        if (ret < 0) {
                perror("thread1 create error");
        }

        pthread_detach(thread1); // detach 실행

        ret = pthread_create(&thread2, NULL, t_function, (void *)message2); // 스레드 생성
        if (ret < 0) {
                perror("thread2 create error");
        }

        pthread_join(thread2, (void **)&status);
        printf("thread2 returns: %d\n", status);

        sleep(5);
        return 0;
}