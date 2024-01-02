/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:16:25 by seayeo            #+#    #+#             */
/*   Updated: 2023/10/05 15:16:26 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, int));
	else if (specifier == 'x' || specifier == 'X')
		count += print_hex((long)(va_arg(ap, unsigned int)), 16, specifier);
	else if (specifier == 'p')
		count += print_void(va_arg(ap, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int		count;

	count = ft_printf("HI %s\n", "what");
	ft_printf("number of chars: %d\n", count);
	count = printf("HI %s\n", "what");
	printf("number of chars: %d\n", count);
	return (0);
}*/