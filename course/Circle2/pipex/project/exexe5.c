/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/20 23:40:21 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void show_error()
{
    perror("error found");
    exit(-1);
}

char *finding_envp(char **envp)
{
            int i;
    char *path;

    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", 5))
        {
            path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
            return (path);
        }
        i++;
    }
    return (NULL);

}
void    free_double(char **collection)
{
    int i;
    i = 0;

    while(collection[i])
    {
        free(collection[i]);
        i++;
    }
    free(collection);
}

char    *finding_path(char **command, char **envp)
{
    //char **cmd_collec;
    char **envp_collec;
    char *path;
    int i;

    //cmd_collec = ft34", cmd_collec[i]);
    //     i++;
    // }           
    path = finding_envp(envp); // leak;
    printf("+++++++경로+++++++\n");
    printf("%s\n", path);
    printf("\n\n\n");         
    envp_collec = ft_split(path, ':');
    i = 0;
    while (envp_collec[i])
    {
        printf("++++envp_collec 잘 됐나 확인하기+++++\n");
        printf("%s\n", envp_collec[i]);
        i++;
    }
    char *temp;
    char *temp2;
    temp = ft_strjoin("/", command[0]); //leak
    printf("\n%s\n", temp);

    i = 0;
    while(envp_collec[i])
    {
        printf("\n와일문 잘 들어갔나?\n");
        temp2 = ft_strjoin(envp_collec[i],temp);
        printf("+++ 결합 잘 됐나? : %s \n", temp2);
        if (access(temp2, X_OK) == -1)
        {
           free(temp2);
            printf("fail\n");
        }
        else
        {
            printf("+++경로 찾았습니다 : %s \n", temp2);
            return (temp2);

        }
        i ++;
    }
            free(temp);
            free(path);
            free_double(envp_collec);
            return(command[0]);
}
void    childexecve(int *fd, char *file,char *command, char **envp)
{
    int outfile;
    char **cmd_split;
    char    *path;
    int i;
    i = 0;

    outfile = open(file, O_CREAT| O_WRONLY | O_TRUNC, 0666);
    if (outfile == -1)
    {
        perror("file open fail");
    }

    if (command == NULL)
    {
        printf("hello world");
        exit(-1);
    }
    close(fd[ft_write]);
    dup2(fd[0], 0);
    dup2(outfile, 1);
    close(outfile);
    cmd_split = ft_split(command, ' ');
    if (cmd_split[0] == NULL)
    {
        printf("%s : command not found", command);
        exit(-1);
    }

        i ++;
    i = 0;

    while (cmd_split[i])
    {
         printf("++++cmd_collec 잘 됐나 확인하기+++\n");
         printf("%s\n", cmd_split[i]);
         i++;
    }
    path = finding_path(cmd_split, envp);
    printf("+++경로 : %s ++++++\n", path);
    if (execve(path, cmd_split, NULL) == -1)
    {
        free_double(cmd_split);
        perror("error found");
        exit(-1);
    }
}


void    parentexecve(int *fd, char *file, char *command, char **envp)
{
    int infile;
    char **cmd_split;
    char    *path;
    int i;
    

    infile = open(file, O_RDONLY);
    if (infile == -1)
    {
        perror("file open failed");
    }

    if (command == NULL)
    {
        printf("hello world");
        exit(-1);
    }
    close(fd[ft_read]);
    dup2(fd[1], 1);
    dup2(infile, 0); // 파일디스크립터는 파일의 번호라는걸 항상 망각하자. 표준 출력, 표준 출력, 표준 에러도 파일이다.(사실 리눅스에서는 모든 것이 파일이다)
    //포인터 fd를 써서 파이프 라인을 하나 만들어 줬다. fd[0]이라는 파일에 표준입력을 가르키게 해서 부모에서 입력한 데이터 혹은 프로세스를 자식 프로세스에게 연결한다.
    //나는 인파일에 값을 읽어와서 아웃파일에 값을 넣어줘야 한다. 파일을 오픈하면 파일디스크립터가 주어진다. 나는 argv[4]에 인자 값을 줘서 파일을 만들어줬다.
    //argv[4]에 인자 값을 줘서 파일의 파일 디스트립터는 infile이다. 이 infile이 0(표준 입력)을 가르키게 해서 infile안에 값이 들어오도록 한다. 자식 프로세스도 마찬가지
    close(infile);
    cmd_split = ft_split(command, ' ');
    i = 0;
    if (cmd_split[0] == NULL)
    {
        printf("%s : command not found", command);
        exit(-1);
    }
    i ++;
    i = 0;
    while (cmd_split[i])
    {
         printf("++++cmd_collec 잘 됐나 확인하기+++\n");
         printf("%s\n", cmd_split[i]);
         i++;
    }
    path = finding_path(cmd_split, envp);
    printf("+++경로 : %s ++++++\n", path);
    if (execve(path, cmd_split, NULL) == -1)
    {
        free_double(cmd_split);
        perror("error found");
        exit(-1);
    }
}


int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int pid;

    if (pipe(fd) < 0)
    {
        perror("pipe error");
        exit(-1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("error found");
    }
    if (argc == 5)
    {
        if(pid > 0)
        {   
            waitpid(pid, NULL, WNOHANG);
            parentexecve(fd, argv[1], argv[2], envp);
        }
        else if (pid == 0)
            childexecve(fd, argv[4], argv[3], envp);
    }

    return 0;
}
