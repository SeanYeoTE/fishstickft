/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:12:52 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/06 12:12:55 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *dw;
	
	dw = (char *)s;
	while (n > 0)
	{
		*dw = c;
		*dw++;
		n--;
	}
	return (b);
}
