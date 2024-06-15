/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 02:56:29 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/14 16:14:40 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> 

// static t_pipe *init_struct(char *argv[], char *envp[] ,int *fd)
// {
//     t_pipe *my_pipe2;
    
//     int errno;
//     my_pipe2 = (t_pipe *)malloc(sizeof(t_pipe));
//     if (!my_pipe2)
//         show_error();
//     my_pipe2 -> fd = fd;
//     my_pipe2 -> file1 = argv[1];
//     my_pipe2 -> cmd1 = argv[2];
//     my_pipe2 -> cmd2 = argv[3];
//     my_pipe2 -> file2 = argv[4];
//     my_pipe2 -> envp = envp;
    
//     return (my_pipe2);
// }

void show_error()
{
    perror("this is what happend");
    exit(1);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int pid;
    int status;
    pid = fork();
    if (argc == 3)
    {
        if (pipe(fd) == -1)
            show_error();
        if (pid == -1) // 오류
            show_error();
        else if (pid == 0) // 자식일때
        {
            close(fd[ft_write]);
            dup2(fd[ft_write], 1);
            childexece(argv, envp);// 자식일때 처리            
        }
        else //부모일때
        {
            close(fd[ft_read]);
            dup2(fd[ft_read], 0);
            parentexece(argv, envp);
        }
        
    }
    else
        show_error();
    //waitpid(pid, &status, WNOHANG);   
    return (0);
}