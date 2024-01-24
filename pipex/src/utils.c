#include "pipex.h"

void error_handle(int i)
{
    if (i == 1)
        ft_putstr_fd("proper input pls\n", 2);
    exit(0);
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

char	*get_env(char **envp)
{
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			return (ft_strdup(&(*envp[5]));
		}
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

