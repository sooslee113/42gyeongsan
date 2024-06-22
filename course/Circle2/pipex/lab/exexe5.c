/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/22 16:22:47 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
안되는 점
1. ./pipex infile "ls" "sleep 3" outfile.
2. infile 읽기 권한 없앴을 때.
3. 
*/
void show_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char *finding_envp(char **envp) {
    int i = 0;
    while (envp[i]) {
        if (ft_strnstr(envp[i], "PATH=", 5)) {
            return ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
        }
        i++;
    }
    return NULL;
}

void free_double(char **collection) {
    int i = 0;
    while (collection[i]) {
        free(collection[i]);
        i++;
    }
    free(collection);
}

char *finding_path(char **command, char **envp) {
    char *path = finding_envp(envp);
    if (!path) return NULL;

    char **envp_collec = ft_split(path, ':');
    free(path);
    if (!envp_collec) return NULL;

    char *temp = ft_strjoin("/", command[0]);
    if (!temp) {
        free_double(envp_collec);
        return NULL;
    }

    for (int i = 0; envp_collec[i]; i++) {
        char *temp2 = ft_strjoin(envp_collec[i], temp);
        if (!temp2) continue;

        if (access(temp2, X_OK) == 0) {
            free(temp);
            free_double(envp_collec);
            return temp2;
        }
        free(temp2);
    }

    free(temp);
    free_double(envp_collec);
    return command[0];
}

void childexecve(int *fd, char *outfile, char *command, char **envp) {
    int out_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (out_fd == -1) show_error("file open fail");

    close(fd[1]);
    if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1) show_error("dup2 fail");
    close(fd[0]);
    close(out_fd);

    char **cmd_split = ft_split(command, ' ');
    if (!cmd_split || !cmd_split[0]) {
        show_error("command split fail");
    }

    char *path = finding_path(cmd_split, envp);
    if (execve(path, cmd_split, envp) == -1) {
        free_double(cmd_split);
        show_error("execve fail");
    }
}

void parentexecve(int *fd, char *infile, char *command, char **envp) {
    int in_fd = open(infile, O_RDONLY);
    if (in_fd == -1) show_error("file open failed");

    close(fd[0]);
    if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1) show_error("dup2 fail");
    close(fd[1]);
    close(in_fd);

    char **cmd_split = ft_split(command, ' ');
    if (!cmd_split || !cmd_split[0]) {
        show_error("command split fail");
    }

    char *path = finding_path(cmd_split, envp);
    if (execve(path, cmd_split, envp) == -1) {
        free_double(cmd_split);
        show_error("execve fail");
    }
}

int main(int argc, char **argv, char **envp) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    int fd[2];
    if (pipe(fd) == -1) show_error("pipe error");

    pid_t pid = fork();
    if (pid == -1) show_error("fork error");

    if (pid == 0) { // Child process
        close(fd[1]); // Close unused write end
        parentexecve(fd, argv[1], argv[2], envp);
    } else { // Parent process
        close(fd[0]); // Close unused read end
        childexecve(fd, argv[4], argv[3], envp);
        waitpid(pid, NULL, 0); // Wait for child process to finish
    }

    return EXIT_SUCCESS;
}