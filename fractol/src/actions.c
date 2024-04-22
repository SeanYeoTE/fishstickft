/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:37:25 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 15:43:14 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keysym, int x, int y, t_fractol *data)
{
	if (keysym == 5)
		data->zoom *= 1.05;
	else if (keysym == 4)
		data->zoom *= 0.95;
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
	else if (keysym == XK_Up || keysym ==65362)
		data->shifty -= 0.5 * data->zoom;
	else if (keysym == XK_Right || keysym == 65363)
		data->shiftx -= 0.5 * data->zoom;
	else if (keysym == XK_Left || keysym == 65361)
		data->shiftx += 0.5 * data->zoom;
	renderer(data);
	return (0);
}
