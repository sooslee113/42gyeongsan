#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    //fd[0] - read
    //fd[1] - write
    //fd[2] - error
    if (pipe(fd) == -1)
    {
        printf("error");
        return 1;
    }
    int id = fork();
    if (id == 0) 
    {
        close(fd[0]); // 자식 프로세스는 파이프의 읽기 끝을 닫습니다.
        int x;
        printf("Input a number: ");
        scanf("%d", &x); // 사용자가 입력한 숫자를 변수 x에 저장합니다.
        if (write(fd[1], &x, sizeof(int)) == -1) // 파이프에 숫자를 씁니다.
        {
            printf("An error ocurred with writing to the pipe\n");
            return 2;
        }
        close(fd[1]);  // 파이프의 쓰기용 파일 디스크립터를 닫습니다.
    }else {
        close(fd[1]); //부모 프로세스에서는 파이프의 쓰기용 파일 디스크립터를 닫습니다.
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1) // 파이프에서 숫자를 읽습니다.
        {
            printf("An error ocurred with reading from the pipe\n");
            return 3;
        }
        close(fd[0]);
        printf("Got from child process %d\n", y);
    }
    return 0;
}