#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
extern char **environ;

int main(int argc, char **argv, char **envp)
{
    char *path = "/bin/ls";
    char *path2 = "/bin/pwd";
    char *argv2[10];
    char *cmd[5];
    int status;

    int pid = fork();
     argv[0] = "ls";
     argv[1] = "-l";
     argv[2] = NULL;
     //argv[2] = NULL;
    argv2[0] = "wc";
    argv2[1] = "-l";
    argv2[2] = NULL;
    // argv2[2] = NULL;   
    // cmd[1] = "-a";
    // cmd[2] = "-l";
    // cmd[3] = NULL;
    
    if(pid == 0)
    {
        execve(path2, argv2, envp);   
    }
    else
    {
        execve("/bin/ls", argv, envp);
    }
}