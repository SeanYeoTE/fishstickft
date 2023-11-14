/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:31:03 by seayeo            #+#    #+#             */
/*   Updated: 2023/11/06 13:49:51 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

size_t	ft_strlen(const char *i);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t	size);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);

char	*joiner(char *buf, char *store);
char	*read_to_storage(int fd, char *store);
char	*extract_line(char *buf);
char	*remains(char *buf);
char	*get_next_line(int fd);

# endif
