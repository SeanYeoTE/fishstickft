#include "pipex.h"

void	child(, char *argv[], char *env[])
{

		execve();

}

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 5)
		error(1);


	pid = fork ();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid[i] == 0)
		child(argv, env);
	else if (pid[i] > 0)
		printf("Parent: Child #%d created with pid = %d\n", i, pid[i]);
	i++;
	parent(pid);
}