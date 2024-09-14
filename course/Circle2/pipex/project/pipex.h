/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 00:32:07 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/23 20:40:22 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# define FT_READ 0
# define FT_WRITE 1

void	child2execve(int *fd, char *file, char *command, char **envp);
void	childexecve(int *fd, char *file, char *command, char **envp);
void	pipex_error(int *file);
void	file_error(char *file);
void	command_error(char *command);
void	fork_error(int pid);
void	null_error(char *command);
void	free_double(char **collection);
char	*finding_path(char **command, char **envp);
char	*finding_envp(char **envp);

#endif
