/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/07 23:33:05 by seayeo           ###   ########.fr       */
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

char	**constantfirstarg(char **cmd_args)
{
	char 	**inter;
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	if (cmd_args[i++])
		count++;
	inter = malloc(sizeof(char *) * count);
	inter[count - 1] = 0;
	inter[0] = ft_strdup(cmd_args[0]);
	

	return (inter);
}

int	execute_command(char *cmd, int input_fd, int output_fd, char **envp)
{
	char	**paths;
	char	*exe_path;
	char	**cmd_args;
	int		status;
	char	*printer;

	//printf("original cmd: %s\n", cmd);
	status = 0;
	paths = find_cmd_path(envp);
	cmd_args = ft_split(cmd, ' ');
	printer = cmd_args[0];
	while (*printer)
	{
		//printf("cmd_args: %s\n", *printer);
		printer++;
	}
	cmd_args = constantfirstarg(cmd_args);
	exe_path = find_executable_path(paths, printer);
	free(paths);

	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	if (exe_path)
		status = execve(exe_path, (char * const *)cmd_args[0], NULL);
	else
		perror_exit("execve");
	return (status);	
}

int	handler(int input_fd, int output_fd, char **argv, char **envp)
{
	pid_t	pid;
	int		status;
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		perror_exit("pipe");
		
	status = 0;
	pid = fork();
	if (pid < 0)
		perror_exit("fork");
	else if (pid == 0)
		execute_command(argv[2], input_fd, pipe_fd[1], envp);
	else
	{
		close(pipe_fd[1]);
		status = execute_command(argv[3], pipe_fd[0], output_fd, envp);
	}
	close(input_fd);
	close(output_fd);
	return (status);
}

int main(int argc, char **argv, char **envp)
{
	int	input_fd;
	int	output_fd;
	
	if (argc != 5)
		perror_exit("invalid input params");
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		perror_exit("open");
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (output_fd == -1)
		perror_exit("open");

	handler(input_fd, output_fd, argv, envp);
	
}
