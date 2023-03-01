/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:10:55 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:10:57 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_move_plan(t_fractol *fractol)
{
	double	x_re;
	double	y_im;

	x_re = (fractol->mouse.mouse_x_re - fractol->complex.min_re)
		/ fractol->complex.re_factor;
	y_im = -(fractol->mouse.mouse_y_im - fractol->complex.max_im)
		/ fractol->complex.im_factor;
	fractol->complex.max_re = fractol->complex.max_re
		+ ((x_re - fractol->mouse.mouse_x) * fractol->complex.re_factor);
	fractol->complex.min_re = fractol->complex.min_re
		+ ((x_re - fractol->mouse.mouse_x) * fractol->complex.re_factor);
	fractol->complex.max_im = fractol->complex.max_im
		+ ((fractol->mouse.mouse_y - y_im) * fractol->complex.im_factor);
	fractol->complex.min_im = fractol->complex.min_im
		+ ((fractol->mouse.mouse_y - y_im) * fractol->complex.im_factor);
}

void	zoom_out(t_fractol *fractol)
{
	double	length_im;

	length_im = (fractol->complex.max_im
			- fractol->complex.min_im) * (2 - ZOOM);
	length_im *= 0.5;
	fractol->complex.max_im = length_im;
	fractol->complex.min_im = -fractol->complex.max_im;
	fractol->complex.max_re = fractol->complex.max_im * SCALE;
	fractol->complex.min_re = -fractol->complex.max_re;
	fractol->complex.re_factor = (fractol->complex.max_re
			- fractol->complex.min_re) / (fractol->window.width);
	fractol->complex.im_factor = (fractol->complex.max_im
			- fractol->complex.min_im) / (fractol->window.height);
}

void	zoom(t_fractol *fractol)
{
	double	length_im;

	length_im = (fractol->complex.max_im
			- fractol->complex.min_im) * ZOOM;
	length_im *= 0.5;
	fractol->complex.max_im = length_im;
	fractol->complex.min_im = -fractol->complex.max_im;
	fractol->complex.max_re = fractol->complex.max_im * SCALE;
	fractol->complex.min_re = -fractol->complex.max_re;
	fractol->complex.re_factor = (fractol->complex.max_re
			- fractol->complex.min_re) / (fractol->window.width);
	fractol->complex.im_factor = (fractol->complex.max_im
			- fractol->complex.min_im) / (fractol->window.height);
}
