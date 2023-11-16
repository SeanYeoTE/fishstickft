/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:32:13 by seayeo            #+#    #+#             */
/*   Updated: 2023/11/16 17:47:48 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *i)
{
	size_t	ct;

	ct = 0;
	if (!i)
		return (0);
	while (i[ct])
		ct++;
	return (ct);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free(s1), str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup("\0"));
	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*ans;

	if (!s1)
		return (0);
	i = -1;
	ans = malloc(ft_strlen(s1));
	if (!ans)
		return (NULL);
	while (s1[++i])
		ans[i] = s1[i];
	ans[i] = '\0';
	return (ans);
}
