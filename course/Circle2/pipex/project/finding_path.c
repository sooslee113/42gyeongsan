#include <stdio.h>
#include "pipex.h"

char* search_envp(char **envp)
{
    int i = 0;
    while(i < 80)
    {
        if (ft_strnstr(envp[i], "PATH=", 5))
            return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5)); //leak
        i ++;
    }
    return NULL;
}

int find_end(char **str)
{
    int i;
    i = 0;
    while(str[i] != NULL)
    {
        printf("+++++%d\n+++++", i);
        i ++;
    }
    return (i);
}

char *where_is_path(char **cmd, char **envp)
{
    printf("\n++++++++++++find_path 함수 잘 들어갔나+++++++++++++++\n");
    printf("cmd = %s\n", *cmd);
            if (access(cmd[0], F_OK) == -1)
        {
            ft_printf("%s : command not found", cmd[0]);
            exit(0);
        }

    int real_cmd;
     if (cmd[0][0] == '/')
    {
        if (access(cmd[0], F_OK) == -1)
        {
            ft_printf("%s : command not found", cmd[0]);
            exit(0);
        }
        printf("if문 들어왔나");
        cmd = ft_split(*cmd, '/');
        //path_check(cmd, envp);
        real_cmd = find_end(cmd) - 1;
        *cmd = cmd[real_cmd];
        *cmd = ft_strjoin("/", *cmd);
         printf("if문 안의 cmd[0] : %s", *cmd);   
    }
    else
        cmd[0] = ft_strjoin("/", cmd[0]);
    printf("\n");
    printf("join 잘 됐나 : %s\n", cmd[0]);
    char *temp;
    int i = 0;
    while(envp[i] != NULL)
    {
        temp = ft_strjoin(envp[i], *cmd);
        if (access(temp, F_OK) == 0)
        {
            printf("++++++++경로 찾았습니다+++++++++++\n");
            free(temp);
            return (envp[i]);
        }
        printf("%s\n", envp[i]);
        free(temp);
        i ++;
    }
    return (NULL);
}

// void    path_check(char **cmd, char **envp)
// {
//     int i;
//     int j;
//     int sign;

//     sign = 0;
//     i = 0;
//     while(cmd[i] != NULL)
//     {
//         j = 0;
//         while(envp[j])
//         {
//             if (ft_strnstr(envp[j], cmd[i], ft_strlen(envp[i])))
//                         break;
//                 exit(0);
//             j ++;
//         }
//     }
// }

char *finding_path(char **cmd, char **envp)
{
    char *path = search_envp(envp);
    envp = ft_split(path, ':'); // leak
    int i = 0;
    printf("\n++++++++++++환경변수 잘 찾았나 체크+++++++++++++++\n");
    printf("환경변수 = %s", path);
    printf("\n++++++++++++split 잘 됐나 체크+++++++++++++++\n");
    while(envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i ++;
    }
    path = where_is_path(cmd, envp);
    printf("경로 : %s\n", path);
    printf("cmd[0] = %s\n", cmd[0]);
    int real_cmd;
    if (cmd[0][0] == '/')
    {
        printf("if문 들어왔나");
        cmd = ft_split(*cmd, '/');
        real_cmd = find_end( cmd) - 1;
        *cmd = cmd[real_cmd];
        *cmd = ft_strjoin("/", *cmd);
         printf("if문 안의 cmd[0] : %s", *cmd);   
    }
    path = ft_strjoin(path, cmd[0]);
    printf("path : %s\n", path);
    return (path);
}

// int main(int argc, char **argv, char **envp)
// {
//     char *file;
//     file = finding_path(argv, envp);
//     printf("경로 = %s\n", file);
//     execve(file, argv[1] , NULL);
// }