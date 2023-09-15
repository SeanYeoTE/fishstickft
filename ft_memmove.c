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
