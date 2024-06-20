#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    char **cmd;
    cmd = ft_split(argv[1], ' ');
    if (argc == 2)
    {
        execve("/usr/bin/ls", cmd, envp);
    }
    return (0);
}