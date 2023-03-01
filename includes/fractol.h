/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:11:49 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:11:51 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_RE 2.25
# define MIN_RE -2.25
# define MAX_IM 1.25
# define MIN_IM -1.25
# define MAX_ITERATION 100
# define K_RE 0.285
# define K_IM 0.013
# define ZOOM 0.90
# define MOVE_STEP 0.02
# define SCALE 1.78

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window
{
	int	width;
	int	height;
	int	max_iterations;
	int	center[2];
}				t_window;

typedef struct s_complex
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	double	c_re;
	double	c_im;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
}				t_complex;

typedef struct s_zoom
{
	double	prev_max_re;
	double	prev_min_re;
	double	prev_max_im;
	double	prev_min_im;
}	t_zoom;

typedef struct s_limit
{
	int	left;
	int	right;
}	t_limit;

typedef struct s_fractal
{
	int		mandelbrot;
	int		julia;
	double	k_re;
	double	k_im;
}	t_fractal;

typedef struct s_mouse
{
	double	mouse_x_re;
	double	mouse_y_im;
	int		mouse_x;
	int		mouse_y;
}	t_mouse;

typedef struct s_fractol
{
	t_vars		vars;
	t_data		img;
	t_window	window;
	t_complex	complex;
	t_zoom		zoom;
	t_limit		limit;
	t_fractal	fractal;
	t_mouse		mouse;
}	t_fractol;

double	ft_atod(const char *nptr);

int		destroy(t_fractol *fractol);
int		mouse_release_hook(int button, int x, int y, t_fractol *fractol);
int		key_hook(int keycode, t_fractol *fractol);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		prepare_julia(t_fractol *fractol, int argc, char *argv[]);
int		initializer(t_fractol *fractol, int argc, char *argv[]);
int		mouse_press_hook(int button, int x, int y, t_fractol *fractol);

size_t	ft_strlen(const char *s);

void	check_is_inside(t_fractol *fractol, int	*is_inside, int *n);
void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
void	zoom_out(t_fractol *fractol);
void	zoom(t_fractol *fractol);
void	zoom_move_plan(t_fractol *fractol);
void	create_fractal(t_fractol *fractol);
void	zoom(t_fractol *fractol);

#endif
