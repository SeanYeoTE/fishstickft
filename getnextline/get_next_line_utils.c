/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:30:55 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/05 16:30:56 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *i)
{
	size_t	ct;

	ct = 0;
	while (i[ct])
		ct++;
	return (ct);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}
