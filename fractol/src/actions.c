/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:37:25 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/15 16:05:08 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keysym, int x, int y, t_fractol *data)
{
	if (keysym == 5)
		data->zoom *= 1.05;
	else if (keysym == 4)
		data->zoom *= 0.95;
	printf("zoom : %f\n\n", data->zoom);
	// printf("The %d key has been pressed\n\n", keysym);
	renderer(data);
	return (0);
}

int	handle_keypress(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
	{
		// printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		exit(1);
	}
	else if (keysym == 61)
	{
		printf("iteration :%d\n\n", data->max_iter);
		data->max_iter += 1;
	}
	else if (keysym == 45)
	{
		printf("iteration :%d\n\n", data->max_iter);
		data->max_iter -= 1;
	}
	// printf("The %d key has been pressed\n\n", keysym);
	renderer(data);
	return (0);
}

int handle_keyrelease(int keysym, t_fractol *data)
{
	printf("The %d key has been released\n\n", keysym);
	return (0);
}
