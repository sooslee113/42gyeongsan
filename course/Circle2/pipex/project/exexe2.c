/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/13 01:46:21 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *parentexece(char**argv, char**envp)
{
    char *parent_path;
    parent_path = finding_path(argv, envp); // 경로찾기
    return (parent_path);
    //execve()
}
int main(int argc, char **argv, char **envp)
{
    char *path;
    char *path2;
    char **cmd;
    char **cmd2;
    int fd[2];
    int pid1;
    int pid2;
    int status;

    cmd = ft_split(argv[1], ' ');
    cmd2 = ft_split(argv[2], ' ');
    if(pipe(fd) == -1)
    {
        perror(" : error");
        exit(1);
    }
    pid1 = fork();
    if(pid1 == 0) // 자식
    {
        close(fd[ft_read]);
        dup2(fd[1], 1);
        close(fd[ft_write]);
        path = parentexece(cmd, envp);
        execve(path, cmd, NULL);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        close(fd[ft_write]);
        dup2(fd[0], 0);
        close(fd[ft_read]);
        path2 = parentexece(cmd2, envp);
        execve(path2, cmd2, NULL);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    return 0;

    return (0);
}