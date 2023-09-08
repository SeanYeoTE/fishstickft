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

char *strchr(const char *s, int c)
{
	int check;
	char	*tmp;
	char	cc;

	tmp = (char *)s;
	cc = (char)c;
	int = 0;
	while (tmp[i] != '\0')
		if (tmp[i] == cc)
			return ((char*)tmp + i);
		i++;
	return (0);
}
