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
#include "get_next_line_bonus.h"

char	*readline(int fd)
{
	char	*buff;
	int 	ans;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ans = read(fd, buff, BUFFER_SIZE);
	if (ans == -1)
		return (free(buff), NULL);
	buff[ans] = '\0';
	return (buff);
}
// read returns how many bytes were successfully read

char	*ft_replaceline(char *buf)
{
	int		len;
	int		i;
	char	*newline;
	int		j;
	
	i = 0;
	j = 0;
	len = ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	newline = malloc((len - i) + 1);
	if (!newline)
		return (NULL);
	i++;
	while (buf[i + j])
	{
		newline[j] = buf[i + j];
		j++;
	}
	newline[j] = '\0';
	return (free(buf), newline);
}
// replace buf with the remainder that was not returned

char	*formline(char	*buf, char *line, int totalen)
{
	char	*final;

	final = malloc(totalen + 1);
	if (!final)
		return (free(final), NULL);
	ft_strlcpy(final, buf, totalen + 1);
	ft_strlcat(final, line, totalen + 1);
	return(free(buf), free(line), final);
}
// joins whatever was previously stored in buf, with the newline that has been read

char	*get_next_line(int fd)
{
	static	char	*buf[1024];
	char			*line;
	int				ct;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	line = readline(fd);
	if (!line)
		return (free(buf), NULL);
	if (!line[0])
		return (free(line), buf);
	if (!buf)
		return (line);
	buf[fd] = formline(buf, line, ft_strlen(buf) + ft_strlen(line));









}
	if (*buf[fd])
	{
		while (buf[fd][ct] && buf[fd][ct] !='\n')
			ct++;
		line = malloc(ct + 2);
		if (!line)
			return (NULL);
		line = ft_strcpy(line, buf[fd]);
	}
	buf[fd] = ft_replaceline(buf[fd]);
	return (line);
}
