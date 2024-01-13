#include "pipex.h"

void error(int i)
{
    if (i == 1)
        ft_putstr_fd("proper input pls\n", 2);
    exit(0);
}
