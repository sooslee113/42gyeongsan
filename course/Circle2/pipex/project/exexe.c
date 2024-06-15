/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/13 01:22:25 by sooslee          ###   ########.fr       */
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
    char *file;
    char **cmd;
    char **cmd2;
    
    cmd = ft_split(argv[1], ' ');
    int i = 0;
    while(cmd[i] != NULL)
    {
        printf("**********cmd[%d] = %s*************\n", i ,cmd[i]);
        i ++;
    }
    file = parentexece(cmd, envp);
    printf("%s\n", file);
    execve(file, cmd, NULL);
    return (0);
}