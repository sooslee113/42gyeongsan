#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    //argv[1] == "testfile.txt";
    if (argc == 2)
    {
        if (0 == access(argv[1], F_OK))
            printf("%s파일이 있습니다.\n", argv[1]);
        if (0 == access(argv[1], R_OK | W_OK))
        {
            printf("읽거나 쓰기가 가능합니다\n");
        }else{
            printf("읽지 못하거나 내용을 변경할 수 없습니다.\n");
            printf("%s\n", strerror(errno));
        }
    }
}
//access를 통해서 main함수를 어떻게 써야할지 대략적인 감을 잡았다. access함수와 exev함수를 이용 할 수 있을 것 같다는 생각이 든다.