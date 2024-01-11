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
#include <signal.h>

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
void	child(void)
{
	printf("\e[36mChild: Hi! I'm a child. I'm in an infinite loop.\e[0m\n");
	while (1)
		continue ;
}

void	kill_and_get_children(pid_t *pid)
{
	int	status;
	int	i;

	printf("Parent: I'm the murderous parent.\n");
	i = 0;
	while (i < 3)
	{
		kill(pid[i], SIGKILL);
		i++;
	}
	printf("Parent: I killed all my children!\n");
	i = 0;
	while (i < 3)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			printf("Parent: Child [%d] terminated normally.\n", pid[i]);
		else if (WIFSIGNALED(status))
		{
			printf("Parent: Child [%d] was interrupted.\n", pid[i]);
			if (WTERMSIG(status) == SIGTERM)
				printf("\e[31mParent: Child [%d] got the %d signal, SIGTERM\e[0m\n",
                            pid[i], WTERMSIG(status));
			 if (WTERMSIG(status) == SIGKILL)
                printf("\e[31mParent: Child [%d] got the %d signal, SIGKILL\e[0m\n",
                            pid[i], WTERMSIG(status));
		}
		i++;
	}
}

int	main(void)
{
	pid_t	pid[3];
	int		i;

	i = 0;
	while (i < 3)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (EXIT_FAILURE);
		else if (pid[i] == 0)
			child();
		else if (pid[i] > 0)
			printf("Parent: Child #%d created with pid = %d\n", i, pid[i]);
		usleep(1000);
		i++;
	}
	kill_and_get_children(pid);
	return (EXIT_SUCCESS);
}
