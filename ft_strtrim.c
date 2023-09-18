/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:42:46 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/18 13:42:52 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*ans;

	i = 0;
	len = ft_strlen(s1);
	ans = 0;
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]))
			len--;
		ans = (char *)malloc(sizeof(char *) * (len - i + 1));
		if (ans)
			ft_strlcpy(ans, &s1[i], len - i + 1);
	}
	return (ans);
}
