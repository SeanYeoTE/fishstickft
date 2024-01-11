#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

void	child(int count, int file1, int cmd1, int cmd2, int file2)
{
	if (count == 0)
	{
		execve();

	}
	else if (count == 1)
	{


	}
}

int	main(int file1, int cmd1, int cmd2, int file2)
{
	pid_t	pid[2];
	int		i;

	i = 0;
	while (i < 2)
	{
		pid[i] = fork ();
		if (pid[i] == -1)
			return (EXIT_FAILURE);
		else if (pid[i] == 0)
			child(i, file1, cmd1, cmd2, file2);
		else if (pid[i] > 0)
			printf("Parent: Child #%d created with pid = %d\n", i, pid[i]);
		i++;
	}
	parent(pid);
}	