/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:52 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/27 16:30:45 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char ** free
void	freechararray(char **v)
{
	char	**tmp;

	if (!v)
		return ;
	tmp = v;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(v);
}

void	closepipes(t_store *vars)
{
	close(vars->fdpipe[0]);
	close(vars->fdpipe[1]);
}

void	freestuff(t_store *vars)
{
	freechararray(vars->paths);
	freechararray(vars->argvs1);
	freechararray(vars->argvs2);
}

// identifys the paths where stuff can be stored in 
char	*findpath(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}
