#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
#include <sys/wait.h>

void error_handle(int i);
char	*my_getenv(char *name, char **env);

#endif