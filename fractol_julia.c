/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:46:12 by mman              #+#    #+#             */
/*   Updated: 2024/05/11 20:36:36 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia_iteration(t_complex z, t_complex c, int max_iter)
{
	int			iter;
	double		real_tmp;
	double		imag_tmp;

	iter = 0;
	while (iter < max_iter)
	{
		real_tmp = z.real * z.real - z.imag * z.imag + c.real;
		imag_tmp = 2 * z.real * z.imag + c.imag;
		z.real = real_tmp;
		z.imag = imag_tmp;
		if (z.real * z.real + z.imag * z.imag > 4)
			break ;
		iter++;
	}
	return (iter);
}

static t_complex	ft_compute_julia_c(t_mlxdata *mlxdata,
	int x, int y, double dx)
{
	t_complex	c;

	c.real = mlxdata->min.real + (double)x * dx * mlxdata->zoom;
	c.imag = mlxdata->min.imag + (double)y * dx * mlxdata->zoom;
	return (c);
}

static void	ft_draw_single_pixel(t_mlxdata *mlxdata, int x, int y, int max_iter)
{
	t_complex	z;
	int			iter;
	int			color;
	int			pixel_index;
	double		dx;

	mlxdata->max_iter = max_iter;
	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	z = ft_compute_julia_c(mlxdata, x, y, dx);
	iter = ft_julia_iteration(z, mlxdata->julia, max_iter);
	color = ft_calculate_color(iter, mlxdata, x, y);
	pixel_index = (y * mlxdata->line_length)
		+ (x * (mlxdata->bits_per_pixel / 8));
	mlxdata->addr[pixel_index] = color >> 16;
	mlxdata->addr[pixel_index + 1] = color >> 8;
	mlxdata->addr[pixel_index + 2] = color;
}

void	ft_draw_julia(t_mlxdata *mlxdata, int max_iter)
{
	int			x;
	int			y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_draw_single_pixel(mlxdata, x, y, max_iter);
		}
	}
}
