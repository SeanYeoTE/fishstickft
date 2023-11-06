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

char	*read_to_storage(int fd)
{
	char	*buf;
	int 	ans;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ans = 1;
	buf[0] = '\0';
	while (!(ft_strchr(buf, '\n')) && ans)
	{
		ans = read(fd, buf, BUFFER_SIZE);
		if (ans == -1)
			return (free(buf), NULL);
		buf[ans] = '\0';
	}
	return (buf);
}
// read returns how many bytes were successfully read
char	*populate_storage(int fd, char *buf)
{
	char	*line;
	int		ct;

	line = NULL;
	ct = 0;
	buf = read_to_storage(fd);
	if (!buf)
		return (NULL);
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


char	*get_next_line(int fd)
{
	static	char	*buf[1024];
	char			*line;
	int				ct;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	ct = 0;
	buf[fd] = readline(fd);
	if (!buf[fd])
		return (NULL);
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
