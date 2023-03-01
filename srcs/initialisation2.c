/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:09:43 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:09:46 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_double(char *nptr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (nptr[i] == '.')
			count++;
		if ((!ft_isdigit(nptr[i]) && nptr[i] != '.') || count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	prepare_julia(t_fractol *fractol, int argc, char *argv[])
{	
	if (argc != 4)
	{
		write(1, "Incorrect arguments: ", 21);
		write(1, "enter the real number and the imaginary number\n", 47);
		return (1);
	}
	if (check_double(argv[2]) || check_double(argv[3]))
	{
		write(1, "Incorrect arguments: ", 21);
		write(1, "enter the real number and the imaginary number\n", 47);
		return (1);
	}
	fractol->fractal.k_re = ft_atod(argv[2]);
	fractol->fractal.k_im = ft_atod(argv[3]);
	return (0);
}
