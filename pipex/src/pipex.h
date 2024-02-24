#ifndef PIPEX_H
# define PIPEX_H


#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"


char	*get_env(char **envp);
char	**find_cmd_path(char **envp);
char	*find_executable_path(char **envp, char *cmd);
void	free2(char **v);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strdup_inverted(const char *s);

#endif