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

void	key_move_position(int direction, t_fractol *fractol)
{
	if (direction == 0)
	{
		fractol->complex.max_im += MOVE_STEP;
		fractol->complex.min_im += MOVE_STEP;
	}
	if (direction == 1)
	{
		fractol->complex.max_re -= MOVE_STEP;
		fractol->complex.min_re -= MOVE_STEP;
	}
	if (direction == 2)
	{
		fractol->complex.max_im -= MOVE_STEP;
		fractol->complex.min_im -= MOVE_STEP;
	}
	if (direction == 3)
	{
		fractol->complex.max_re += MOVE_STEP;
		fractol->complex.min_re += MOVE_STEP;
	}
}

void	key_zoom_out(t_fractol *fractol)
{
	double	center_re;
	double	center_im;

	center_re = fractol->complex.min_re
		+ fractol->window.width * 0.5 * fractol->complex.re_factor;
	center_im = fractol->complex.max_im
		- fractol->window.height * 0.5 * fractol->complex.im_factor;
	zoom_out(fractol);
	fractol->complex.max_re += center_re;
	fractol->complex.min_re += center_re;
	fractol->complex.max_im += center_im;
	fractol->complex.min_im += center_im;
}

void	key_zoom(t_fractol *fractol)
{
	double	center_re;
	double	center_im;

	center_re = fractol->complex.min_re
		+ fractol->window.width * 0.5 * fractol->complex.re_factor;
	center_im = fractol->complex.max_im
		- fractol->window.height * 0.5 * fractol->complex.im_factor;
	zoom(fractol);
	fractol->complex.max_re += center_re;
	fractol->complex.min_re += center_re;
	fractol->complex.max_im += center_im;
	fractol->complex.min_im += center_im;
}

int	key_hook(int keycode, t_fractol *fractol)
{	
	if (keycode == 65307)
		destroy(fractol);
	if (keycode == 65362)
		key_move_position(0, fractol);
	if (keycode == 65361)
		key_move_position(1, fractol);
	if (keycode == 65364)
		key_move_position(2, fractol);
	if (keycode == 65363)
		key_move_position(3, fractol);
	if (keycode == 32)
		key_zoom(fractol);
	if (keycode == 100)
		key_zoom_out(fractol);
	create_fractal(fractol);
	mlx_put_image_to_window(fractol->vars.mlx,
		fractol->vars.win, fractol->img.img, 0, 0);
	return (0);
}
