/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:09:00 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:09:02 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	next_complex_mandelbrot(t_fractol *fractol)
{
	fractol->complex.z_im = 2 * fractol->complex.z_re
		* fractol->complex.z_im + fractol->complex.c_im;
	fractol->complex.z_re = fractol->complex.z_re2
		- fractol->complex.z_im2 + fractol->complex.c_re;
}

void	next_complex_julia(t_fractol *fractol)
{
	fractol->complex.z_im = 2 * fractol->complex.z_re
		* fractol->complex.z_im + fractol->fractal.k_im;
	fractol->complex.z_re = fractol->complex.z_re2
		- fractol->complex.z_im2 + fractol->fractal.k_re;
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->img.addr + (y * fractol->img.line_length
			+ x * (fractol->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	check_is_inside(t_fractol *fractol, int	*is_inside, int *n)
{
	*is_inside = 1;
	*n = 0;
	while ((*n)++ < fractol->window.max_iterations)
	{
		fractol->complex.z_re2 = fractol->complex.z_re * fractol->complex.z_re;
		fractol->complex.z_im2 = fractol->complex.z_im * fractol->complex.z_im;
		if (fractol->complex.z_re2 + fractol->complex.z_im2 > 4)
		{
			*is_inside = 0;
			return ;
		}
		if (fractol->fractal.mandelbrot)
			next_complex_mandelbrot(fractol);
		if (fractol->fractal.julia)
			next_complex_julia(fractol);
	}
	return ;
}

void	create_fractal(t_fractol *fractol)
{
	int	x;
	int	y;
	int	is_inside;
	int	n;

	y = -1;
	while (++y < fractol->window.height)
	{
		fractol->complex.c_im = fractol->complex.max_im
			- y * fractol->complex.im_factor;
		x = -1;
		while (++x < fractol->window.width)
		{
			fractol->complex.c_re = fractol->complex.min_re
				+ x * fractol->complex.re_factor;
			fractol->complex.z_re = fractol->complex.c_re;
			fractol->complex.z_im = fractol->complex.c_im;
			check_is_inside(fractol, &is_inside, &n);
			if (!is_inside)
				my_mlx_pixel_put(fractol, x, y, 0x00190027 * n);
			else
				my_mlx_pixel_put(fractol, x, y, 0x00000000);
		}
	}
}
