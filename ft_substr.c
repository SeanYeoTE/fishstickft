/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:31:12 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/11 17:31:13 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((size_t)ft_strlen(s) < len)
		len = (size_t)ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ans[j] = s[i];
			j++;
		}
		i++;
	}
	ans[j] = 0;
	return (ans);
}
