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

char	*ft_strdup(const char *s)
{
	int		len;
	int		tmp;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	tmp = 0;
	while (tmp < len)
	{
		str[tmp] = s[tmp];
		tmp++;
	}
	str[tmp] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (size_t)(ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (!size)
		return (srclen);
	while (src[i] && (dstlen + i + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	if (dstlen > size)
		return (srclen + size);
	return (srclen + dstlen);
}