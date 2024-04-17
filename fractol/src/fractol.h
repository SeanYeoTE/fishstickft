#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)

typedef struct s_complex
{  
	// real
	double	x;

	// imaginary
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	char	*name;

	void	*mlx_connection;
	void	*mlx_window;
	int		color;
	int		max_iter;
	
	double	juliax;
	double	juliay;
	double	shiftx;
	double	shifty;
	double	zoom;
	t_img	img;

}	t_fractol;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	my_pixel_put(t_img *img, int x, int y, int color);
t_complex	complex_square(t_complex z);
t_complex	complex_add(t_complex z1, t_complex z2);

int	handle_mouse(int keysym, int x, int y, t_fractol *data);
int	handle_keypress(int keysym, t_fractol *data);
int handle_keyrelease(int keysym, t_fractol *data);

void	init(t_fractol *data);
void	triggers(t_fractol *data);
void	setbase(t_fractol *data);

void	renderer(t_fractol *data);
int	mandelbrot(int x, int y, t_fractol *data);
void	original_eq(t_complex *z, t_complex *c, t_fractol *data, t_complex *tmp);
void	pixel_painter(int x, int y, t_fractol *data);
double	convert(double newstart, double newend, double oldstart, double oldend, double value);

#endif