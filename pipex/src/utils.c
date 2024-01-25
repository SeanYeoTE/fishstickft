#include "pipex.h"

char	*get_env(char **envp)
{
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_strdup(&(*envp[5])));
		envp++;
	}
	return (NULL);
}

char	**find_cmd_path(char **envp)
{
	char	**possible_paths;
	char	*all_path;

	all_path = get_env(envp);
	possible_paths = ft_split(all_path, ':');
	if (all_path)
		free(path);
	return (possible_paths);
}

char	**find_executable_path(char **envp)
{
	char	**paths;


	if (access(paths, X_OK) == 0)
	{
		paths = ft_strdup();

	}
}

void	find_executable_path(const char *executable, char *cmd_path)
{
	char *path = getenv("PATH");
	char *path_copy = ft_strdup(path);
	char *dir = strtok(path_copy, ":");
	char full_path[MAX_PATH_LEN];

	while (dir != NULL) 
	{
		// Check if the file exists and is executable
		if (access(full_path, X_OK) == 0)
		{
			strcpy(cmd_path, full_path);
			cmd_path[strlen(cmd_path)] = '\0';
			free(path_copy);
			return ;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	cmd_path[0] = '\0';  // Executable not found
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}