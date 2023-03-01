/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 05:10:30 by dgauvin           #+#    #+#             */
/*   Updated: 2022/03/29 05:10:32 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int	destroy(t_fractol *fractol)
{
	mlx_destroy_image(fractol->vars.mlx, fractol->img.img);
	mlx_destroy_window(fractol->vars.mlx, fractol->vars.win);
	mlx_destroy_display(fractol->vars.mlx);
	free(fractol->vars.mlx);
	exit(0);
	return (0);
}

double	power(int nbr, int power)
{
	double	result;

	result = nbr;
	while (power > 0)
	{
		result *= nbr;
		power--;
	}
	return ((double)result);
}

void	ft_atod2(const char *nptr, double *result, int *i)
{
	int	j;

	j = 0;
	if (nptr[*i] == '.')
		(*i)++;
	while (nptr[*i] >= '0' && nptr[*i] <= '9' && j < 7)
	{
		*result = *result + (nptr[*i] - 48) / power(10, j);
		(*i)++;
		j++;
	}
}

double	ft_atod(const char *nptr)
{
	double	sign;
	double	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	ft_atod2(nptr, &result, &i);
	return (sign * result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}	
