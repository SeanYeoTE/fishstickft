/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:30:28 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/05 16:30:32 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*readline(int fd)
{
	char	*buff;
	int 	ans;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ans = read(fd, buff, BUFFER_SIZE);
	if (ans < 0)
		return (free(buff), NULL);
	buff[ans] = '\0';
	return (buff);
}

// read returns how many bytes were successfully read
char	*ft_addtext(char *buf, int fd)
{
	char	*newbuf;
	char	*next;
	int		newlen;

	next = readline(fd);
	if (!next)
		return (free(buf), NULL);
	if (!buf)
		return (next);
	newlen = ft_strlen(buf) + ft_strlen(next);
	newbuf = malloc(newlen + 1);
	if (!newbuf)
		return (free(newbuf), NULL);
	newbuf = ft_strdup(buf);
	// ^^ this seems unnecessary
	ft_strlcat(newbuf, next, newlen + 1);
	return (free(buf), free(next), newbuf);
}


char	*get_next_line(int fd)
{
	static	char	*buf[4096];
	char			*line;
	size_t			oldlen;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (ft_strchr(buf[fd], '\n') == 0)
	{
		oldlen = ft_strlen(buf[fd]);
		buf[fd] = ft_addtext(buf[fd], fd);
		if (oldlen  == ft_strlen(buf[fd]) && buf[fd])
			line = ft_substr(buf[fd], 0, ft_strlen(buf[fd]));
	if (line)
	{
		return (line);
	}
	}
	return (get_next_line(fd));
}