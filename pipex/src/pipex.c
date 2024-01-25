/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/01/24 22:42:07 by seayeo           ###   ########.fr       */
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

void execute_command(char *cmd[], int input_fd, int output_fd, char *env[]) {
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

int main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		perror_exit("invalid input params");


	const char *file1 = argv[1];

	char *cmd1_args[2];
	cmd1_args[0] = malloc(MAX_PATH_LEN);
	cmd1_args[1] = NULL;
	find_executable_path(argv[2], cmd1_args[0]);

	char *cmd2_args[3];
	cmd2_args[0] = malloc(MAX_PATH_LEN);
	cmd2_args[1] = NULL;
	cmd2_args[2] = NULL;
	find_executable_path(argv[3], cmd2_args[0]);

	const char *file2 = argv[4];

	int pipe_fd[2];
	if (pipe(pipe_fd) == -1) {
		perror_exit("pipe");
	}

	// First command: cmd1 < file1
	int input_fd = open(file1, O_RDONLY);
	if (input_fd == -1) {
		perror_exit("open");
	}

	pid_t pid1 = fork();
	if (pid1 < 0)
		perror_exit("fork");
	else if (pid1 == 0) {
		// Child process
		// Redirect output to write to the pipe
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1) {
			perror_exit("dup2");
		}
		if (close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1) {
			perror_exit("close");
		}
		execute_command(cmd1_args, input_fd, STDOUT_FILENO, envp);
		exit(EXIT_SUCCESS);
	}
	// Close write end of pipe in parent
	if (close(input_fd) == -1 || close(pipe_fd[1]) == -1) {
		perror_exit("close");
	}
	

	// Second command: cmd2 > file2
	int output_fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (output_fd == -1) {
		perror_exit("open");
	}

	pid_t pid2 = fork();
	if (pid2 < 0) {
		perror_exit("fork");
	} else if (pid2 == 0) {
		// Child process
		// Redirect input to read from the pipe
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1) {
			perror_exit("dup2");
		}
		if (close(pipe_fd[0]) == -1) {
			perror_exit("close");
		}  
		execute_command(cmd2_args, STDIN_FILENO, output_fd, envp);
		exit(EXIT_SUCCESS);
	}
	// Close read end of pipe in parent
	if (close(output_fd) == -1 || close(pipe_fd[0]) == -1) {
		perror_exit("close");
	}
	
	// Wait for both child processes to finish
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}
