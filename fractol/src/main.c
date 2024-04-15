/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:35:34 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/15 15:54:57 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	data;
	int			store;

	if (argc == 1)
		ft_putstr_fd("mandelbrot / julia\n", 1);
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		data.name = argv[1];
		init(&data);
	}
	// init(&data);
}