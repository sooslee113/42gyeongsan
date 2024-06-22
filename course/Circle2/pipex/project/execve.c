/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:33:35 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/22 21:30:10 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*finding_envp(char **envp)
{
	char	*path;
	int		i;

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

void	free_double(char **collection)
{
	int	i;

	i = 0;
	while (collection[i])
	{
		free(collection[i]);
		i++;
	}
	free(collection);
}

char	*finding_path(char **command, char **envp)
{
	char	**envp_collec;
	char	*path;
	char	*temp;
	char	*temp2;
	int		i;

	path = finding_envp(envp);
	envp_collec = ft_split(path, ':');
	temp = ft_strjoin("/", command[0]);
	i = 0;
	while (envp_collec[i])
	{
		temp2 = ft_strjoin(envp_collec[i], temp);
		if (access(temp2, X_OK) == -1)
			free(temp2);
		else
			return (temp2);
		i ++;
	}
	free(temp);
	free(path);
	free_double(envp_collec);
	return (command[0]);
}

void	childexecve(int *fd, char *file, char *command, char **envp)
{
	char		**cmd_split;
	char		*path;
	int			outfile;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		file_error(file);
	if (command == NULL)
		null_error(command);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(outfile);
	cmd_split = ft_split(command, ' ');
	if (cmd_split[0] == NULL)
		command_error(command);
	path = finding_path(cmd_split, envp);
	if (execve(path, cmd_split, NULL) == -1)
	{
		free_double(cmd_split);
		perror("error found");
		exit(-1);
	}
}

void	parentexecve(int *fd, char *file, char *command, char **envp)
{
	char		**cmd_split;
	char		*path;
	int			infile;

	infile = open(file, O_RDONLY);
	if (infile == -1)
		file_error(file);
	if (command == NULL)
		null_error(command);
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(infile);
	cmd_split = ft_split(command, ' ');
	if (cmd_split[0] == NULL)
		command_error(command);
	path = finding_path(cmd_split, envp);
	if (execve(path, cmd_split, NULL) == -1)
	{
		free_double(cmd_split);
		perror("error found");
		exit(-1);
	}
}
