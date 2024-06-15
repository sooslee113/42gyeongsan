/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:32:07 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/14 21:23:12 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

#define ft_read 0
#define ft_write 1

typedef struct s_pipe
{
	int *fd;
	char *file1;
	char *file2;
	char *cmd1;
	char *cmd2;
	char **envp;
} t_pipe;

void	show_error();
char 	*finding_path(char **argv, char **envp);
char	*where_is_path(char **argv, char **envp);
char	*search_envp(char **envp);
void    parentexecve(int *fd, char *path, char **cmd, char **envp, char **argv);
void    childexecve(int *fd, char *path2, char **cmd2, char **envp, char **argv);
//void    childexece(char**argv, char**envp);


#endif