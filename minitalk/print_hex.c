/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:20 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/11 16:06:21 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(long n, int base, char c)
{
	int		count;
	char	*symbols;

	if (c == 'x')
		symbols = "0123456789abcdef";
	else if (c == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_hex(-n, base, c) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_hex(n / base, base, c);
		return (count + print_hex(n % base, base, c));
	}
}

int	print_unsignedhex(unsigned long int n)
{
	int				count;
	char			*symbols;
	unsigned int	base;

	base = 16;
	symbols = "0123456789abcdef";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_unsignedhex(n / base);
		return (count + print_unsignedhex(n % base));
	}
}
