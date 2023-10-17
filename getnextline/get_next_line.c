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
include "get_next_line.h"

char	*readline(int fd)
{
	char	buff[BUFFER_SIZE];
	int 	ans;

	if (!buff)
		return (NULL);
	ans = read(fd, buff, BUFFER_SIZE)
	if (ans < 0)
		return (free(ans), NULL);
	buff[ans] = '\0';
	return (buff);
	ft_strdup()
}

char	*get_next_line(int fd)
{
	static	char	*buf[4096];

	size_t			oldlen;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	
	
}