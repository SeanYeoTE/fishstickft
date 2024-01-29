/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/01/29 16:44:27 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define MAX_PATH_LEN 4096

void perror_exit(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

void execute_command(char *cmd[], int input_fd, int output_fd, char *env[])
{
	pid_t pid = fork();

	if (pid == -1) {
		perror_exit("fork");
	} else if (pid == 0) {
		// Child process
		// Redirect input
		if (input_fd != STDIN_FILENO) {
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		// Redirect output
		if (output_fd != STDOUT_FILENO) {
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
		// Execute the command with provided environment variables
		execve(cmd[0], cmd, env);
		perror_exit("execve");
	}
}

int	handler(int input_fd, int output_fd, char **argv, char **envp)
{
	char	**paths = find_cmd_path(envp);
	char	*exe_path;

	exe_path = find_executable_path(paths, argv[2]);
	printf("%s\n", exe_path);
	
	execute_command(exe_path, input_fd, output_fd, envp);

	int i = 0;
	while (paths[i]) {
		//printf("%s\n", paths[i]);
		i++;
	}
	while (paths[i]) {
		free(paths[i]);
		i++;
	}
	free(paths);
}

int main(int argc, char **argv, char **envp)
{
	int	input_fd;
	int	output_fd;
	
	if (argc != 5)
		perror_exit("invalid input params");
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1) {
		perror_exit("pipe");
	}
	input_fd = open(argv[0], O_RDONLY);
	if (input_fd == -1)
		perror_exit("open");
	output_fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (output_fd == -1)
		perror_exit("open");

	handler(input_fd, output_fd, argv, envp);
	
}
