/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:52 by seayeo            #+#    #+#             */
/*   Updated: 2024/02/24 19:25:05 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char **envp)
{
	while (envp && *envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*(envp + 5));
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
		return (ft_strdup(cmd));
	//printf("Finding executable Path %s\n", cmd);
	cmd_ender = ft_strjoin("/", cmd);
	//printf("Path with CMD: %s\n", cmd_ender);
	path = NULL;
	while (envp && *envp)
	{
		path = ft_strjoin(*envp, cmd_ender);
		//printf("Path tested: %s\n", path);
		if (access(path, X_OK) == 0)
		{
			free(cmd_ender);
			//printf("path is %s\n", path);
			return (path);
		}
		free(path);
		path = NULL;
		envp++;
	}
	free(cmd_ender);
	return (NULL);
}

void	free2(char **v)
{
	char	**p;

	if (!v)
		return ;
	p = v;
	while (*v)
	{
		free(*v);
		v++;
	}
	free(p);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	size_t	tmp;
	char	*str;

	len = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	tmp = 0;
	while (tmp < len)
	{
		str[tmp] = s[tmp];
		tmp++;
	}
	str[tmp] = '\0';
	return (str);
}

char	*ft_strdup_inverted(const char *s)
{
	int		len;
	int		tmp;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	tmp = 0;
	while (tmp < len)
	{
		if (s[tmp] != '"')
			str[tmp] = s[tmp];
		tmp++;
	}
	str[tmp] = '\0';
	return (str);
}
