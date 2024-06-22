/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcollec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:44:14 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/22 21:29:53 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_error(int *fd)
{
	ft_printf("%d\n", *fd);
	perror("pipe is not connacted ");
	exit(-1);
}

void	file_error(char *file)
{
	ft_printf("permission denied : %s", file);
	exit(-1);
}

void	command_error(char *command)
{
	ft_printf("%s : command not found", command);
	exit(-1);
}

void	fork_error(int pid)
{
	ft_printf("pid : %d", pid);
	perror("fork fail ");
	exit(-1);
}

void	null_error(char *command)
{
	ft_printf("permission denied : %s", command);
	exit(-1);
}
