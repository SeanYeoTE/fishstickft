/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:15:49 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/27 16:31:14 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// this function take the paths that have already been split,
// join with the cmd given, to find the location where it 
// can be executed.
char	*findprocesspath(t_store *vars, int processnum)
{
	int		i;
	char	*temp;
	char	*joined;

	i = 0;
	joined = NULL;
	while ((vars->paths)[i])
	{
		temp = ft_strjoin((vars->paths)[i], "/");
		if (processnum == 1)
			joined = ft_strjoin(temp, vars->argvs1[0]);
		else
			joined = ft_strjoin(temp, vars->argvs2[0]);
		if (access(joined, X_OK) == 0)
			break ;
		free(joined);
		joined = NULL;
		i++;
	}
	free(temp);
	return (joined);
}

// execution layer for first process
int	p1child(t_store *vars, char **envp)
{
	int		execveresult;
	char	*exepath;

	execveresult = 0;
	exepath = findprocesspath(vars, 1);
	if (exepath == NULL)
	{
		perror("Path not found");
		free(exepath);
		return (1);
	}
	dup2(vars->fdpipe[1], 1);
	close(vars->fdpipe[0]);
	dup2(vars->input_fd, 0);
	if (exepath)
		execveresult = execve(exepath, vars->argvs1, envp);
	else
		perror("first process error");
	if (exepath)
		free(exepath);
	return (execveresult);
}

// execution layer for second process
int	p2child(t_store *vars, char **envp)
{
	int		execveresult;
	char	*exepath;

	execveresult = 0;
	exepath = findprocesspath(vars, 0);
	if (exepath == NULL)
	{
		perror("Path not found");
		free(exepath);
		return (1);
	}
	dup2(vars->fdpipe[0], 0);
	close(vars->fdpipe[1]);
	dup2(vars->output_fd, 1);
	execveresult = execve(exepath, vars->argvs2, envp);
	if (execveresult == -1)
		perror("second process error");
	if (exepath)
		free(exepath);
	return (0);
}

// setup all the necessary values into struct
int	secondary(t_store *vars, char **argv, char **envp)
{
	int errr;

	errr = 0;
	if (pipe(vars->fdpipe) < 0)
		return (1);
	vars->input_fd = open(argv[1], O_RDONLY);
	if (vars->input_fd < 0)
	{
		perror("error opening input file");
		errr = 1;
	}
	vars->output_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (vars->output_fd < 0)
	{
		perror("error opening output file");
		errr = 1;
	}
	vars->path = findpath(envp);
	vars->paths = ft_split(vars->path + 5, ':');
	vars->argvs1 = ft_split(argv[2], ' ');
	vars->argvs2 = ft_split(argv[3], ' ');
	vars->envp = envp;
	return (errr);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_store	vars;
	int		pid1;
	int		pid2;
	int		error;

	if (argc != 5)
		return (1);
	error = secondary(&vars, argv, envp);
	if (error == 1)
		return (1);
	pid1 = fork();
	if (pid1 == 0)
		p1child(&vars, envp);
	pid2 = fork();
	if (pid2 == 0 && pid1 != 0)
		p2child(&vars, envp);
	else
	{
		closepipes(&vars);
		freestuff(&vars);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
