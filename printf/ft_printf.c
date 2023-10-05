#include "ft_printf.h"

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int	count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base)) + 1;
	}
	else if (n < base)
		return (print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}
int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
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
		count += print_format(*(++format), ap);
	else
		count += write(1, format, 1);
    } 
}
