/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:37:25 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 23:31:08 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keysym, int x, int y, t_fractol *data)
{
	if (keysym == 5)
		data->zoom *= 1.05;
	else if (keysym == 4)
		data->zoom *= 0.95;
	else if (keysym == 3)
		color_changer(data);
	renderer(data);
	return (0);
}

int	handle_keypress(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_connection, data->img.img_ptr);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		exit(1);
	}
	else if (keysym == 61)
		data->max_iter += 5;
	else if (keysym == 45)
		data->max_iter -= 5;
	else if (keysym == XK_Down || keysym == 65364)
		data->shifty += 0.5 * data->zoom;
	else if (keysym == XK_Up || keysym == 65362)
		data->shifty -= 0.5 * data->zoom;
	else if (keysym == XK_Right || keysym == 65363)
		data->shiftx -= 0.5 * data->zoom;
	else if (keysym == XK_Left || keysym == 65361)
		data->shiftx += 0.5 * data->zoom;
	renderer(data);
	return (0);
}

int	color_changer(t_fractol *data)
{
	// int	colors[12];

	int colors[12] = {0xFF0000, 0x00FF00, 0x0000FF,
		0xFFFF00, 0xFF00FF, 0x00FFFF, 0xFFA500,
		0x800080, 0xFF1493, 0x00FF7F, 0xFF6347,
		0x9400D3};
	data->firstcolor = colors[data->colnum % 12];
	data->secondcolor = colors[data->colnum % 12 + 7];
	data->colnum++;
	return (0);
}
