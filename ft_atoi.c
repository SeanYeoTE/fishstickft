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
	int	i;
	int	parity;
	int	ans;

	i = 0;
	parity = 0;
	ans = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			parity++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (str[i] - '0') + (ans * 10);
		i++;
	}
	return (ans * (parity * -1));
}
