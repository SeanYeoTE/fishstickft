/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:05:39 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 23:19:15 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	convert(double newstart, double newend, double oldend, double value)
{
	double	oldstart;

	oldstart = 0;
	return ((newend - newstart) / (oldend - oldstart) * value + newstart);
}

void	original_eq(t_complex *c, t_complex *z, t_fractol *fractal,
	t_complex *temp)
{
	if (ft_strncmp("julia", fractal->name, 5) == 0)
	{
		z->x = (convert(-2, +2, WINDOW_WIDTH, temp->x)
				* fractal->zoom) + fractal -> shiftx;
		z->y = (convert(2, -2, WINDOW_HEIGHT, temp->y)
				* fractal->zoom) + fractal -> shifty;
		c->x = fractal->juliax;
		c->y = fractal->juliax;
	}
	else
	{
		z->x = 0;
		z->y = 0;
		c->x = (convert(-2, +2, WINDOW_WIDTH, temp->x) * fractal->zoom)
			+ fractal->shiftx;
		c->y = (convert(2, -2, WINDOW_HEIGHT, temp->y) * fractal->zoom)
			+ fractal->shifty;
	}
}

// c is the actual starting point
// z is the calculated points
int	mandelbrot(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_complex	temp;

	temp.x = x;
	temp.y = y;
	i = 0;
	original_eq(&c, &z, fractal, &temp);
	while (i < fractal->max_iter)
	{
		z = complex_add(complex_square(z), c);
		if ((z.x * z.x) + (z.y * z.y) > 4.0)
			return (i);
		++i;
	}
	return (i);
}

void	renderer(t_fractol *fractal)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			color = mandelbrot(x, y, fractal);
			if (color == fractal->max_iter)
				my_pixel_put(&fractal->img, x, y, BLACK);
			else
			{
				color = convert(fractal->firstcolor, fractal->secondcolor,
						fractal->max_iter, color);
				my_pixel_put(&fractal->img, x, y, color);
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
