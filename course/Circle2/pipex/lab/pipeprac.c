#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 50

int main(int argc, char **argv)
{
    int fd1[2];// 파이프 입구와 출구의 디스크립터를 저장할 정수형 배열 선언
    char str1[] ="who are you?"; // 문자열 배열에 who are you를 저장
    char str2[] ="thank you for your msg"; // 문자열 배열에 thank you for your msg 저장 
    char buf[BUF_SIZE]; // 
    int pid; // 자식 프로세스 pid를 저장할 변수 선언
    pipe(fd1);// 파이프 생성 fd[0] 과 fd[1]에 파이프의 출구와 입구에 파일디스크립터가 할당되었다.
    pid = fork(); // 자식 프로세스 생성
    if (pid == 0) //
    {
        write(fd1[1], str1, sizeof(str1));
        //sleep(2);
        read(fd1[0], buf, BUF_SIZE);
        printf("Child proc output: %s\n", buf);
    }
    else
    {
        read(fd1[0], buf, BUF_SIZE);
        printf("parent output is : %s\n", buf);
        write(fd1[1], str2, sizeof(str2));
        sleep(3);
    }
    return 0;
}