/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:32:07 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/20 13:47:01 by sooslee          ###   ########.fr       */
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


void	show_error();
char    *i_want_to_find_path(char**cmd, char**envp);
//void    childexecve(int *fd,char *file1, char *command, char **envp);
//void    childexecve(int *fd,char *file1, char *command, char **envp);
char 	*finding_path(char **command, char **envp);
char	*where_is_path(char **argv, char **envp);
char	*search_envp(char **envp);
char    **reduce(char **cmd);
int     find_end(char **str);
void    free_double(char   **twostr);
// void    childexecve2(int *fd, char *outfile, char*cmd, char **envp);
// void    parentexecve2(int *fd, char *infile, char*cmd, char **envp);


#endif