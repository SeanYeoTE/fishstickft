/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:02:07 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/06 11:02:13 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int x)
{
	if (x >= 'a' && x <= 'z')
		return (1);
	if (x >= 'A' && x <= 'Z')
		return (1);
	else
		return (0);
}