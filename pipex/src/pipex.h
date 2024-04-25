/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:17:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/25 14:17:12 by seayeo           ###   ########.fr       */
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



struct s_pipex {
	char	**argvs1;
	char	**argvs2;
	int		fdpipe[2];
};

void	freechararray(char **arr);

void	setstructure(char *argv[], struct s_pipex *pipexstruct, char *path);
void	closepipes(struct s_pipex *pipexstruct);

char	*findprocesspath(char *path,
			struct s_pipex pipexstruct, int processnum);
int		p1child(char *path, char *envp[],
			struct s_pipex pipexstruct, int inputfd);

int		p2child(char *path, char *envp[],
			struct s_pipex pipexstruct, int outputfd);

char	*findpath(char *envp[]);
void	freestuff(struct s_pipex *pipexstruct);


#endif