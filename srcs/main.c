/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:10:13 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:10:16 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->vars.win, 2, 1L << 0, key_hook, &(fractol->vars));
	mlx_hook(fractol->vars.win, 4, 1L << 2, mouse_press_hook, &(fractol->vars));
	mlx_hook(fractol->vars.win,
		5, 1L << 3, mouse_release_hook, &(fractol->vars));
}

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc < 2)
	{
		write(1, "You must enter a fractal name: Mandelbrot or Julia\n", 51);
		return (1);
	}
	if (initializer(&fractol, argc, argv))
		return (1);
	create_fractal(&fractol);
	mlx_put_image_to_window(fractol.vars.mlx,
		fractol.vars.win, fractol.img.img, 0, 0);
	handle_hooks(&fractol);
	mlx_hook(fractol.vars.win, 17, 1L << 17, destroy, &(fractol.vars));
	mlx_loop(fractol.vars.mlx);
	return (0);
}
