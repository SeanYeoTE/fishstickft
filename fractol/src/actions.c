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
	(void)x;
	(void)y;
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
	data->firstcolor = color_picker(data->colnum % 12);
	data->secondcolor = color_picker(data->colnum % 12 + 7);
	data->colnum++;
	return (0);
}

int	color_picker(int num)
{
	if (num == 0)
		return (0xFF0000);
	else if (num == 1)
		return (0x00FF00);
	else if (num == 2)
		return (0x0000FF);
	else if (num == 3)
		return (0xFFFF00);
	else if (num == 4)
		return (0xFF00FF);
	else if (num == 5)
		return (0x00FFFF);
	else if (num == 6)
		return (0xFFA500);
	else if (num == 7)
		return (0x800080);
	else if (num == 8)
		return (0xFF1493);
	else if (num == 9)
		return (0x00FF7F);
	else if (num == 10)
		return (0xFF6347);
	else
		return (0x9400D3);
}
