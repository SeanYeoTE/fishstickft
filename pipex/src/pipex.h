/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:17:10 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/25 18:49:53 by seayeo           ###   ########.fr       */
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



typedef struct s_pipex {
	char	**argvs1;
	char	**argvs2;
	int		fdpipe[2];
	char	**paths;
	char	*path;
	int		input_fd;
	int		output_fd;
}	t_store ;

void	freechararray(char **arr);

void	setstructure(char *argv[], t_store *vars, char *path);
void	closepipes(t_store *vars);

char	*findprocesspath(char *path, t_store vars, int processnum);
int		p1child(char *path, char *envp[], t_store vars, int inputfd);
int		p2child(char *path, char *envp[], t_store vars, int outputfd);

char	*findpath(char *envp[]);
void	freestuff(t_store *vars);


#endif