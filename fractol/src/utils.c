/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seayeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:48:58 by seayeo            #+#    #+#             */
/*   Updated: 2024/04/22 23:15:38 by seayeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// currently dont need to offset pixels cuz the window size remains constant
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

// (x + yi)(x + yi )
// x^2 + -1(y^2) + 2xyi
t_complex	complex_square(t_complex z)
{
	t_complex	ans;

	ans.x = (z.x * z.x) - (z.y * z.y);
	ans.y = 2 * z.x * z.y;
	return (ans);
}

// complex number addition
t_complex	complex_add(t_complex z1, t_complex z2)
{
	t_complex	ans;

	ans.x = z1.x + z2.x;
	ans.y = z1.y + z2.y;
	return (ans);
}
