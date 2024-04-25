/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:39:52 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/25 18:59:02 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	closepipes(struct s_pipex *pipexstruct)
{
	close(pipexstruct->fdpipe[0]);
	close(pipexstruct->fdpipe[1]);
}

void	freestuff(t_store *vars)
{
	int	i;

	i = 0;
	while (vars->paths && vars->paths[i])
	{
		free(vars->paths[i]);
		vars->paths[i] = NULL;
		i++;
	}
	free(vars->paths);
	vars->paths = NULL;
	i = 0;
	while (vars->argvs1 && vars->argvs1[i])
	{
		free(vars->argvs1[i]);
		vars->argvs1[i] = NULL;
		i++;
	}
	free(vars->argvs1);
	vars->argvs1 = NULL;
	i = 0;
	while (vars->argvs2 && vars->argvs2[i])
	{
		free(vars->argvs2[i]);
		vars->argvs2[i] = NULL;
		i++;
	}
	free(vars->argvs2);
	vars->argvs2 = NULL;
}
