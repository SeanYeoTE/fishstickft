/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/01/14 19:04:32 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute_cmd(char *cmd, char **args)
{
    if (execve(cmd, args, NULL) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

void	child(char *argv[], char *env[])
{
	printf("\e[36mChild: Hi! I'm a child. I'm in an infinite loop.\e[0m\n");
	while (1)
		continue ;
}


int main(int argc, char **argv, char *env[])
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: %s file1 cmd1 cmd2 file2\n", 2);
		return 1;
	}
	int	fd1 = open(argv[1], O_RDONLY);
	int	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if (fd1 == -1 || fd2 == -1)
	{
		perror("open");
		return 1;
	}

	int pipefd[2];
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return 1;
	}

    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        dup2(fd1, STDIN_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        char *cmd1_args[] = {argv[2], NULL};
        execute_cmd(argv[2], cmd1_args);

    return 0;
}