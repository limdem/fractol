/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:09:14 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 11:22:23 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	mouse_move_position(t_fractol *fractol, int x, int y)
{
	double	x_re;
	double	y_im;

	fractol->complex.re_factor = (fractol->complex.max_re
			- fractol->complex.min_re) / (fractol->window.width);
	fractol->complex.im_factor = (fractol->complex.max_im
			- fractol->complex.min_im) / (fractol->window.height);
	x_re = (x - fractol->mouse.mouse_x)
		* fractol->complex.re_factor;
	y_im = -(y - fractol->mouse.mouse_y)
		* fractol->complex.im_factor;
	fractol->complex.max_re = fractol->complex.max_re - x_re;
	fractol->complex.min_re = fractol->complex.min_re - x_re;
	fractol->complex.max_im = fractol->complex.max_im - y_im;
	fractol->complex.min_im = fractol->complex.min_im - y_im;
}

int	mouse_release_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 1)
	{
		mouse_move_position(fractol, x, y);
		create_fractal(fractol);
		mlx_put_image_to_window(fractol->vars.mlx,
			fractol->vars.win, fractol->img.img, 0, 0);
	}
	return (0);
}

int	mouse_press_hook(int button, int x, int y, t_fractol *fractol)
{
	fractol->mouse.mouse_x = x;
	fractol->mouse.mouse_y = y;
	fractol->mouse.mouse_x_re = fractol->complex.min_re
		+ fractol->mouse.mouse_x * fractol->complex.re_factor;
	fractol->mouse.mouse_y_im = fractol->complex.max_im
		- fractol->mouse.mouse_y * fractol->complex.im_factor;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom_out(fractol);
		else
			zoom(fractol);
		zoom_move_plan(fractol);
		create_fractal(fractol);
		mlx_put_image_to_window(fractol->vars.mlx,
			fractol->vars.win, fractol->img.img, 0, 0);
	}
	return (0);
}
