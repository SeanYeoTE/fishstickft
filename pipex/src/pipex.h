#ifndef PIPEX_H
# define PIPEX_H


#include <stdlib.h>
# include <stdio.h>
#include <sys/wait.h>
# include <unistd.h>
#include <fcntl.h>
# include "../libft/libft.h"

void error_handle(int i);
char	*my_getenv(char *name, char **env);

#endif