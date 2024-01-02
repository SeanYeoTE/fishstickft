/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:04 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/11 16:04:05 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	unsigned long	num;
	int				count;

	num = n;
	count = 0;
	if (num >= 10)
	{
		count += 1 + print_unsigned(num / 10);
		print_char((num % 10) + '0');
	}
	else
		count += print_char(num + '0');
	return (count);
}
