/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:17:43 by seayeo            #+#    #+#             */
/*   Updated: 2024/01/09 10:17:45 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*int	main(int argc, char *argv[])
{
	int fd[2];

	if (pipe(fd) == -1)
		return 1;
	int pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	if (pid1 == 0)
	{
		//child process 

	}
}*/

int	main(void)
{
	pid_t	pid;
	int		*status;

	status = 0;
	printf("Fork Here.\n");
	pid = fork();

	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("this is the child pid %d\n", pid);
		sleep(2);
		printf("child done\n");
	}
	else if (pid > 0)
	{
		printf("this is parent %d\n", pid);
		waitpid(pid, status, 0);
		printf("parent done\n");
	}
	return (0);
}