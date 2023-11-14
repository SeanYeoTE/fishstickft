/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:30:28 by seayeo            #+#    #+#             */
/*   Updated: 2023/11/06 13:49:39 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char	*joiner(char *store, char *buf)
{
	char	*ans;

	ans = ft_strjoin(store, buf);
	return (ans);
}

char	*read_to_storage(int fd, char *store)
{
	char	*buf;
	int 	ans;

	if (!store)
		store = ft_calloc(1, 1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ans = 1;
	while (ans > 0)
	{
		ans = read(fd, buf, BUFFER_SIZE);
		if (ans == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ans] = '\0';
		store = joiner(store, buf);
		if (ft_strchr(buf, '\n') != -1)
			break ;
	}
	free(buf);
	return (store);
}
	
char	*extract_line(char *buf)
{
	char	*line;
	int		i;
	int		ptr;

	i = 0;
	if (!buf[i])
		return (NULL);
	i = ft_strchr(buf, '\n');
	ptr = -1;
	if (i != -1)
	{
		line = ft_calloc(i + 2, sizeof(char));
		while (++ptr < i)
			line[ptr] = buf[ptr];
		line[ptr++] = '\n';
	}
	else
	{
		line = ft_calloc(ft_strlen(buf) + 1, sizeof(char));
		while(++ptr < (int)ft_strlen(buf))
			line[ptr] = buf[ptr];
	}
	return (line);
}


char	*remains(char *buf)
{
	char	*leftover;
	int		cutoff;
	int 	newindexer;

	cutoff = 0;
	while (buf[cutoff] && buf[cutoff] != '\n')
			cutoff++;
	if (!buf[cutoff])
		return (free(buf), NULL);
	leftover = ft_calloc((ft_strlen(buf) - cutoff + 1), sizeof(char));
	newindexer = 0;
	cutoff++;
	while (buf[cutoff])
		leftover[newindexer++] = buf[cutoff++];
	return (free(buf), leftover);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	buf[fd] = read_to_storage(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = extract_line(buf[fd]);
	buf[fd] = remains(buf[fd]);
	return (line);
}
