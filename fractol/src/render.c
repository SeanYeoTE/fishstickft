/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:05:39 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/15 16:00:28 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	renderer(t_fractol *data)
{
	int x;
	int y;
	int	valid;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
			pixel_painter(x, y, data);
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img.img_ptr, 0, 0);
}

void	pixel_painter(int x, int y, t_fractol *data)
{
	int	valid;
	int	color;
	
	valid = mandelbrot(x, y, data);
	if (valid == data->max_iter)
	{
		my_pixel_put(&data->img, x, y, WHITE);
	}
	else
	{
		color = convert(BLACK, WHITE, 0, data->max_iter, valid);
		my_pixel_put(&data->img, x, y, color);
	}
}

void	original_eq(t_complex *z, t_complex *c, t_fractol *data, t_complex *tmp)
{
	z->x = convert(-2, +2, 0, WINDOW_WIDTH, tmp->x) * data->zoom;
	z->y = convert(+2, -2, 0, WINDOW_HEIGHT, tmp->y) * data->zoom;
	if (!ft_strncmp(data->name, "julia", 5))
	{
		c->x = data->juliax;
		c->x = data->juliay;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	mandelbrot(int x, int y, t_fractol *data)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int	n;

	n = 0;
	tmp.x = x;
	tmp.y = y;
	original_eq(&z, &c, data, &tmp);
	while (n < data->max_iter)
	{
		tmp = complex_square(z);
		z = complex_add(tmp, c);
		
		if ((z.x * z.x) + z.y * z.y > 4.0)
			return (n);
		n++;
	}
	return (n);
}

// (z^2 + c)^2 + c 
double	convert(double newstart, double newend, double oldstart, double oldend, double value)
{
	return (newend - newstart)/(oldend - oldstart) * value + newstart;
}