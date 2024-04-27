/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:17:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/27 16:33:18 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**argvs1;
	char	**argvs2;
	int		fdpipe[2];
	char	**paths;
	int		input_fd;
	int		output_fd;

	char	*path;
	char	**envp;
}	t_store ;

int		secondary(t_store *vars, char **argv, char **envp);
char	*findprocesspath(t_store *vars, int processnum);
int		p1child(t_store *vars, char **envp);
int		p2child(t_store *vars, char **envp);

void	freechararray(char **arr);
void	closepipes(t_store *vars);
void	freestuff(t_store *vars);
char	*findpath(char *envp[]);

#endif