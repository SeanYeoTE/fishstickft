#include "pipex.h"

void	child(char *argv[], char *env[])
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

    const char *variableName = "PATH";

    // Use getenv to get the value of the environment variable
    char *path = getenv(variableName);

    // Check if the environment variable exists
    if (path != NULL) {
        // Print the value of the environment variable
        printf("%s=%s\n", variableName, path);
    } else {
        // The environment variable does not exist
        printf("%s not found in the environment.\n", variableName);
    }

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