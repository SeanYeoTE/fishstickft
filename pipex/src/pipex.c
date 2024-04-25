/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:15:49 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/25 18:59:19 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findprocesspath(char *path, t_store vars, int processnum)
{
	int		i;
	char	*temp;
	
	i = 0;
	while (vars.paths[i])
	{
		temp = ft_strjoin(vars.paths[i], "/");
		if (processnum == 1)
			path = ft_strjoin(temp, vars.argvs1[0]);
		else
			path = ft_strjoin(temp, vars.argvs2[0]);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
		free(temp);
		path = NULL;
		i++;
	}
	if (path != NULL && access(path, F_OK) == 0)
		return (path);
	else
		return (NULL);
}

int	p1child(char *path, char *envp[], t_store vars, int inputfd)
{
	int		execveresult;

	path = findprocesspath(path, vars, 1);
	if (path == NULL)
	{
		perror("Path not found");
		return (1);
	}
	dup2(vars.fdpipe[1], 1);
	close(vars.fdpipe[0]);
	dup2(inputfd, 0);
	execveresult = execve(path, vars.argvs1, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	return (0);
}

int	p2child(char *path, char *envp[], t_store vars, int outputfd)
{
	int		execveresult;

	path = findprocesspath(path, vars, 2);
	if (path == NULL)
	{
		perror("Path not found");
		return (1);
	}
	dup2(vars.fdpipe[0], 0);
	close(vars.fdpipe[1]);
	dup2(outputfd, 1);
	execveresult = execve(path, vars.argvs2, envp);
	if (execveresult == -1)
		perror("smth wrong with executing second process. Terminate now");
	free(path);
	return (0);
}

char	*findpath(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	if (ft_strncmp("PATH=", path, 5) == 0)
		return (path);
	else
		return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_store			vars;
	int				pid1;
	int				pid2;
	int				pid1status;
	int				pid2status;
	
	if (argc != 5)
		return (1);
	if (pipe(vars.fdpipe) == -1)
		return (1);
	secondary(argv, envp, vars);
	pid1 = fork();
	if (pid1 == 0)
		p1child(vars.path, envp, vars, vars.input_fd);
	pid2 = fork();
	if (pid2 == 0 && pid1 != 0)
		p2child(vars.path, envp, vars, vars.output_fd);
	waitpid(pid1, &pid1status, 0);
	waitpid(pid2, &pid2status, 0);
	closepipes(&vars);
	freestuff(&vars);
	return (0);
}

int secondary(char **argv, char **envp, t_store vars)
{
	vars.output_fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (vars.output_fd < 0)
	{
		// perror("Error in output file");
		return (0);
	}
	vars.input_fd = open(argv[1], O_RDONLY);
	if (vars.input_fd < 0)
	{
		// perror("Error opening file");
		return (0);
	}
	vars.path = findpath(envp);
	vars.paths = ft_split(vars.path + 5, ':');
	vars.argvs1 = ft_split(argv[2], ' ');
	vars.argvs2 = ft_split(argv[3], ' ');
}