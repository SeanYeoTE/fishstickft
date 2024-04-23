/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:35:34 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 23:19:35 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

int	main(int argc, char **argv)
{
	t_fractol	data;

	setbase(&data);
	if (argc == 1)
		ft_putstr_fd("mandelbrot / julia\n", 1);
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		data.name = argv[1];
		init(&data);
	}
	if (argc == 2 && ft_strncmp(argv[1], "julia", 5) == 0)
		ft_putstr_fd("no x and y input\n", 1);
	if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		data.name = argv[1];
		data.juliax = atodbl(argv[2]);
		data.juliay = atodbl(argv[3]);
		init(&data);
	}
}
