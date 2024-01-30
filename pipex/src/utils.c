/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:52 by seayeo            #+#    #+#             */
/*   Updated: 2024/01/29 16:16:23 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char **envp)
{
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_strdup((ft_split(*envp, '=')[1])));
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
		free(all_path);
	return (possible_paths);
}

char	*find_executable_path(char **envp, char *cmd)
{
	char	*cmd_ender;
	char	*path;

	if (access(cmd, X_OK) == 0)
	{
		return (ft_strdup(cmd));
	}
	printf("Finding executable Path%s\n", cmd);
	cmd_ender = ft_strjoin("/", cmd);
	path = NULL;
	while (envp && *envp)
	{
		path = ft_strjoin(*envp, cmd_ender);
		if (access(path, X_OK) == 0)
		{
			return (ft_strdup(path));
		}
		*envp++;
	}
	return (NULL);
}