/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:23:03 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/11 11:23:04 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
/*{
	size_t	len;

	len = 0;
	if (!dest || !src)
		return (NULL);
	if (src < dest)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dest);
}*/
{
	size_t	i;
	char	*cdest;
	char	tmp[65535];

	cdest = (char*)dest;
	i = 0;
	if (len > 65535)
		return (NULL);
	ft_memcpy(tmp, src, len);
	while (i < len)
	{
		cdest[i] = tmp[i];
		i++;
	}
	return (cdest);
}
