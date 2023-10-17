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
