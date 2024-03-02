/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:02:40 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/11 16:02:41 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}
