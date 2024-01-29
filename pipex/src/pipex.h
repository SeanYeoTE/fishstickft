#ifndef PIPEX_H
# define PIPEX_H


#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

void error_handle(int i);

char	*get_env(char **envp);
char	**find_cmd_path(char **envp);
char	*find_executable_path(char **envp, char *cmd);

#endif