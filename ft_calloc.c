/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:59:09 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/11 15:59:10 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t	size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, nmemb);
	return (ptr);
}

/*if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}*/