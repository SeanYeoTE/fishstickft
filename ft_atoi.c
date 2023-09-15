/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:05:29 by seayeo            #+#    #+#             */
/*   Updated: 2023/09/11 12:05:29 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ans;
	int	parity;
	char	*tmp;

	ans = 0;
	parity = 0;
	tmp = (char *)str;
	while (*tmp == ' ' || (*tmp >= 9 && *tmp <= 13))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
	{
		if (*tmp == '-')
			parity++;
		tmp++;
	}
	while (*tmp >= '0' && *tmp <= '9')
	{
		ans = (ans * 10) + (*tmp - '0');
		tmp++;
	}
	return (ans * (parity * -1));
}
