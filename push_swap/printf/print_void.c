/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:03:16 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/11 16:03:17 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_void(void *n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += print_str("(nil)");
	else
	{
		count += print_str("0x");
		count += print_unsignedhex((unsigned long int)n);
	}
	return (count);
}
