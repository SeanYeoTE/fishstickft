#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_strlen(char *i);
void 	*memset(void *s, int c, size_t n);
void 	bzero(void *s, size_t n);
void 	*memcpy(void *dest, const void *src, size_t n);

#endif