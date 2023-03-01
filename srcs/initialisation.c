/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:10:00 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:10:02 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	initialize_win_img(t_fractol *fractol)
{
	fractol->vars.mlx = mlx_init();
	if (!fractol->vars.mlx)
		return (1);
	fractol->vars.win = mlx_new_window(fractol->vars.mlx,
			WIDTH, HEIGHT, "Fractol");
	if (!fractol->vars.win)
		return (1);
	fractol->img.img = mlx_new_image(fractol->vars.mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		return (1);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bits_per_pixel),
			&(fractol->img.line_length), &(fractol->img.endian));
	if (!fractol->img.addr)
		return (1);
	return (0);
}

int	check_args(t_fractol *fractol, int argc, char *argv[])
{
	if (fractol->fractal.mandelbrot && argc != 2)
	{
		write(1, "Incorrect arguments, ", 21);
		write(1, "type: Mandelbrot\n", 17);
		return (1);
	}
	if (fractol->fractal.julia)
		if (prepare_julia(fractol, argc, argv))
			return (1);
	return (0);
}

int	determine_fractal(t_fractol *fractol, char *argv)
{
	if (*argv == 'M' || *argv == 'J')
		*argv += 32;
	if (!ft_strncmp(argv, "mandelbrot", 10) && ft_strlen(argv) == 10)
	{
		fractol->fractal.mandelbrot = 1;
		fractol->fractal.julia = 0;
		return (0);
	}
	else if (!ft_strncmp(argv, "julia", 5) && ft_strlen(argv) == 5)
	{
		fractol->fractal.julia = 1;
		fractol->fractal.mandelbrot = 0;
		return (0);
	}
	write(1, "Please enter a correct fractal: Mandelbrot or Julia\n", 52);
	return (1);
}

int	initializer(t_fractol *fractol, int argc, char *argv[])
{
	if (determine_fractal(fractol, *(argv + 1)))
		return (1);
	if (check_args(fractol, argc, argv))
		return (1);
	if (initialize_win_img(fractol))
		return (1);
	fractol->window.height = HEIGHT;
	fractol->window.width = WIDTH;
	fractol->window.center[0] = fractol->window.width / 2;
	fractol->window.center[1] = fractol->window.height / 2;
	fractol->window.max_iterations = MAX_ITERATION;
	fractol->complex.max_re = MAX_RE;
	fractol->complex.min_re = MIN_RE;
	fractol->complex.max_im = MAX_IM;
	fractol->complex.min_im = MIN_IM;
	fractol->complex.re_factor = (fractol->complex.max_re
			- fractol->complex.min_re) / (fractol->window.width);
	fractol->complex.im_factor = (fractol->complex.max_im
			- fractol->complex.min_im) / (fractol->window.height);
	return (0);
}
