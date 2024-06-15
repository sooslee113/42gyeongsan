/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/15 15:55:03 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	show_error()
{
    perror(" : error");
    exit(1);
}
char    *i_want_to_find_path(char**argv, char**envp)
{
    char *parent_path;
    parent_path = finding_path(argv, envp); // 경로찾기
    return (parent_path);
}
void    parentexecve(int *fd, char *path, char **cmd, char **envp, char **argv)
{
    int infile;
    
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
    {
        show_error();
    }
    close(fd[ft_read]);
    dup2(fd[1], 1);
    path = i_want_to_find_path(cmd, envp);
    execve(path, cmd, NULL);
}

void    childexecve(int *fd, char *path2, char **cmd2, char **envp, char **argv)
{
    int outfile;

    outfile = open(argv[4], O_CREAT, O_WRONLY | O_TRUNC, 0644);
    if (outfile == -1)
    {
        show_error();
    }
    close(fd[ft_write]);
    dup2(fd[0], 0);
    path2 = i_want_to_find_path(cmd2, envp);
    execve(path2, cmd2, NULL);
}

int main(int argc, char **argv, char **envp)
{
    char *path;
    char *path2;
    char **cmd;
    char **cmd2;
    int fd[2];
    int pid1;

    if (argc == 5)
    {
        path = NULL;
        path2 = NULL;
        cmd = ft_split(argv[2], ' ');
        cmd2 = ft_split(argv[3], ' ');
        if(pipe(fd) == -1)
            show_error();
        pid1 = fork();
        if (pid1 == -1)
            perror(" : error");
        if (pid1 == 0)
            childexecve(fd, path2, cmd2, envp, argv);
        else
            parentexecve(fd, path, cmd, envp, argv);
        waitpid(pid1, NULL, WNOHANG);
    }
    return (0);
}