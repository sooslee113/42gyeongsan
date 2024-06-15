#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fd1, ret;
    char message[32] = {"STDERR from fd1\n"};

    // 그림 1번
    fd1 = open(argv[1], O_RDWR, S_IRUSR|S_IWUSR);
    if (fd1 < 0)
    {
        printf("%s\n", strerror(errno));
        exit(0);
    }
    // 표준 입출력으로 print됨
    printf("file open\n");

    //fd1의 파일 디스크립터가 명시한 STDOUT_FILENO의 파일 디스크립터로 복제된다.
    //그림 2번 표준출력이 가르키는 걸 argv[1]로 바꾼다.
    ret = dup2(fd1, STDOUT_FILENO);

    //fd1으로 출력됨, printf는 표준 출력이다. 표준출력(번호 1)이 argv[1]을 가르키고 있어서 printf출력 결과는 argv[1] 파일로 간다. 
    printf("fd1 : %d, ret : %d\n", fd1, ret);

    //STDERR_FILENO 디스크립터가 명시된 fd1으로 복제됨
    //그림 3번 fd1이 에러를 가르킨다. 
    ret = dup2(STDERR_FILENO, fd1);

    //fd1은 에러로 출력됨 지금 fd1은 에러를 가르키고 있다.
    write(fd1, message, strlen(message));

    //stdout이 file로 써짐
    printf("printf를 썼지만 파일에 기록됨\n");

    close(fd1);
}