#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int	i, fd;

	fd = open("test.txt", O_RDONLY);
	for (i = 0; i < 7; i++)
		printf("%s", get_next_line(fd));
	return (0);
}
