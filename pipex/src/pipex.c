/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:15:49 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/25 14:15:55 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	freechararray(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
} */
void	freechararray(char **v)
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

char	*findprocesspath(char *path,
struct s_pipex pipexstruct, int processnum)
{
	int		i;
	char	*temp;
	char	**looper;
	i = 0;
	looper = ft_split(path + 5, ':');
	while (looper[i])
	{
		temp = ft_strjoin(looper[i], "/");
		if (processnum == 1)
			path = ft_strjoin(temp, pipexstruct.argvs1[0]);
		else
			path = ft_strjoin(temp, pipexstruct.argvs2[0]);
		if (access(path, F_OK) == 0)
			break ;
		free (temp);
		free (path);
		path = NULL;
		i++;
	}
	freechararray(looper);
	if (path != NULL && access(path, F_OK) == 0)
		return (path);
	else
		return (NULL);
}

int	p1child( char *path, char *envp[], struct s_pipex pipexstruct, int inputfd)
{
	int		execveresult;

	path = findprocesspath(path, pipexstruct, 1);
	if (path == NULL)
	{
		perror("Path not found");
		return (1);
	}
	dup2(pipexstruct.fdpipe[1], 1);
	close(pipexstruct.fdpipe[0]);
	dup2(inputfd, 0);
	execveresult = execve(path, pipexstruct.argvs1, envp);
	if (execveresult == -1)
		perror("Execve failed in P1child. Terminating Now");
	free(path);
	return (0);
}

int	p2child(char *path, char *envp[], struct s_pipex pipexstruct, int outputfd)
{
	int		execveresult;

	path = findprocesspath(path, pipexstruct, 2);
	if (path == NULL)
	{
		perror("Path not found");
		return (1);
	}
	dup2(pipexstruct.fdpipe[0], 0);
	close(pipexstruct.fdpipe[1]);
	dup2(outputfd, 1);
	execveresult = execve(path, pipexstruct.argvs2, envp);
	if (execveresult == -1)
		perror("smth wrong with executing. Terminate now");
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
	struct s_pipex	pipexstruct;
	char			*path;
	int				input_fd;
	int				output_fd;
	int				pid1;
	int				pid2;
	int				pid1status;
	int				pid2status;
	
	if (argc != 5)
		return (1);
	path = findpath(envp);
	if (pipe(pipexstruct.fdpipe) == -1)
		return (1);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	output_fd = open(argv[4], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (output_fd < 0)
	{
		perror("Error in output file");
		return (0);
	}
	// setstructure(argv, &pipexstruct, path);
	pipexstruct.argvs1 = ft_split(argv[2], ' ');
	pipexstruct.argvs2 = ft_split(argv[3], ' ');
	// if (pipexstruct.err == 1)
	// {
	// 	freestuff(&pipexstruct);
	// 	return (0);
	// }
	pid1 = fork();
	if (pid1 == 0)
		p1child(path, envp, pipexstruct, input_fd);
	pid2 = fork();
	if (pid2 == 0 && pid1 != 0)
		p2child(path, envp, pipexstruct, output_fd);
	closepipes(&pipexstruct);
	waitpid(pid1, &pid1status, 0);
	waitpid(pid2, &pid2status, 0);
	freestuff(&pipexstruct);
	return (0);
}