/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/24 19:25:04 by seayeo           ###   ########.fr       */
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
void	child(int input_fd, int *pipe_fd, char **env, char **argv);
void	parent(int output_fd, int *pipe_fd, char **env, char **argv);

void perror_exit(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*pathfinder(char *argv, char **env)
{
	char	*realpath;
	char	**tabpath;
	char	*temppath;
	int		i;

	tabpath = ft_split(get_env(env), ':');
	i = 0;
	while (tabpath[i++])
	{
		temppath = ft_strjoin(tabpath[i], "/");
		realpath = ft_strjoin(temppath, argv);
		free(temppath);
		if (access(realpath, F_OK) == 0)
		{
			free(tabpath);
			return (realpath);
		}
		free(realpath);
	}
	free2(tabpath);
	perror("error could not find binary");
	return (NULL);
}

char	**ft_split_custom(char *s)
{
	char 	*inter;
	int		cmd_size;
	char	**ret;
	
	if (s == NULL || *s == 0)
		return (NULL);
	inter = s;
	while (*inter && *inter != ' ')
	{
		inter++;
	}
	if (inter != NULL)
		ret = ft_split(s, ' ');
	else
	{
		cmd_size = 3;
		ret = (char **)malloc(sizeof(char *) * cmd_size);
		ret[0] = ft_strndup(s, inter - s);
		ret[1] = ft_strdup_inverted(inter);
		printf("ret[1] = %s\n", ret[1]);
		ret[2] = NULL;
	}
	return (ret);
}

void execute_command(char *argv, char **env)
{
	char	**argtab;
	char	*path;
	
	printf("argv: %s\n", argv);
	argtab = ft_split_custom(argv);
	path = pathfinder(argtab[0], env);
	if (execve(path, argtab, env) == -1)
	{
		free2(argtab);
		free(path);
		perror_exit("could not execute");
	}
	free2(argtab);
	free(path);
}

void	handler(int input_fd, int output_fd, char **argv, char **envp)
{
	pid_t	pid;
	int pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		perror_exit("pipe");
	pid = fork();
	if (pid < 0)
		perror_exit("fork");
	else if (pid == 0)
	{
		child(input_fd, pipe_fd, envp, argv);
	}
	else
	{
		//close(pipe_fd[1]);
		parent(output_fd, pipe_fd, envp, argv);
		close(pipe_fd[0]);
	}
}

// write to pipe_fd[1], read from pipe_fd[0]
void	parent(int output_fd, int *pipe_fd, char **env, char **argv)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	execute_command(argv[3], env);
}

void	child(int input_fd, int *pipe_fd, char **env, char **argv)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	execute_command(argv[2], env);
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
	return (0);
}
