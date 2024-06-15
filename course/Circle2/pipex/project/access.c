#include <stdio.h>
#include "pipex.h"

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
        }
    }
}