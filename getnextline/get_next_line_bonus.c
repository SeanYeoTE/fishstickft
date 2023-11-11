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
#include "get_next_line_bonus.h"

char	*read_to_storage(int fd)
{
	char	*buf;
	int 	ans;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ans = read(fd, buf, BUFFER_SIZE);
	if (ans < 0)
		return (free(buf), NULL);
	buf[ans] = '\0';
	return (buf);
}
// read returns how many bytes were successfully read

char	*populate_storage(int fd, char *oldstash)
{
	int		totalen;
	char	*newstash;
	char	*buf;

	buf = read_to_storage(fd);
	totalen = ft_strlen(buf) + ft_strlen(oldstash);
	newstash = malloc(totalen + 1);
	if (!newstash)
		return (NULL);
	if (!buf)
		return (free(oldstash), NULL);
	if (!buf[0])
		return (free(buf), oldstash);
	if (!oldstash)
		return (buf);
	ft_strlcpy(newstash, oldstash, totalen + 1);
	ft_strlcat(newstash, buf, totalen + 1);
	return (free(buf), free(oldstash), newstash);  
}
// mallocs new storage to store line and (chars from read to storage function) stored in buf

char	*ft_replaceline(char *oldstash)
{
	int		len;
	char	*newstash;
	int		stopper;

	stopper = 0;
	len = ft_strlen(oldstash);
	if (!oldstash[stopper])
		return (free(oldstash), NULL);
	while (oldstash[stopper] && oldstash[stopper] != '\n')
		stopper++;
	stopper++;
	newstash = ft_substr(oldstash, stopper, len);
	if (!newstash)
		return (free(oldstash), NULL);
	return (free(oldstash), newstash);
}

char	*get_next_line(int fd)
{
	static	char	*stash[4096];
	char			*line;
	int				cutoff;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	stash[fd] = populate_storage(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	if (ft_strchr(stash[fd], '\n') == 0)
	{
		if (!line)
		{
			cutoff = 0;
			while (stash[fd][cutoff] != '\n' && stash[fd][cutoff])
				cutoff++;
			line = ft_substr(stash[fd], 0, cutoff);		
		}
		if (line)
		{
			stash[fd] = ft_replaceline(stash[fd]);
			return (line);	
		}
	}
	return (get_next_line(fd));
}
