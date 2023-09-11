/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:06:23 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/08 13:06:24 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	cc;

	tmp = (char *)s;
	cc = (char)c;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == cc)
			return ((char *)tmp + i);
		i++;
	}
	return (0);
}
