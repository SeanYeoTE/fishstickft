/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:06:05 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 23:13:54 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	freeall(t_fractol *data)
{
	mlx_destroy_image(data->mlx_connection, data->img.img_ptr);
	free(data->img.img_ptr);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
}

void	init(t_fractol *data)
{
	data->mlx_connection = mlx_init();
	if (data->mlx_connection == NULL)
		return ;
	data->mlx_window = mlx_new_window(data->mlx_connection, WINDOW_WIDTH,
			WINDOW_HEIGHT, data->name);
	if (data->mlx_window == NULL)
		freeall(data);
	data->img.img_ptr = mlx_new_image(data->mlx_connection, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (data->img.img_ptr == NULL)
		freeall(data);
	data->img.pixels_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	triggers(data);
	color_changer(data);
	renderer(data);
	mlx_loop(data->mlx_connection);
}

void	triggers(t_fractol *data)
{
	mlx_hook(data->mlx_window, KeyPress, KeyPressMask,
		handle_keypress, data);
	mlx_hook(data->mlx_window, ButtonPress, ButtonPressMask,
		handle_mouse, data);
}

void	setbase(t_fractol *data)
{
	data->zoom = 1.0;
	data->max_iter = 50;
	data->shiftx = 0.0;
	data->shifty = 0.0;
	data->juliax = 0.0;
	data->juliay = 0.0;
	data->colnum = 0;
	data->firstcolor = 0;
	data->secondcolor = 0;
}
