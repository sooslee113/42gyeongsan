#include "pipex.h"

int main()
{
    int signal;
    char temp[100] = "/////aa///usr/bin/ls";

    signal = access(temp, F_OK);
    printf("%d", signal);
}