/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/05/11 20:35:50 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		real_tmp;
	double		imag_tmp;

	z.real = 0;
	z.imag = 0;
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

static void	ft_process_pixel(t_mlxdata *mlxdata, int x, int y, long double dx)
{
	t_complex	c;
	int			iter;
	int			color;
	int			pixel_index;

	c.real = mlxdata->min.real + (long double)x * dx * mlxdata->zoom;
	c.imag = mlxdata->min.imag + (long double)y * dx * mlxdata->zoom;
	iter = ft_mandelbrot_iteration(c, mlxdata->max_iter);
	color = ft_calculate_color(iter, mlxdata, x, y);
	pixel_index = (y * mlxdata->line_length)
		+ (x * (mlxdata->bits_per_pixel / 8));
	mlxdata->addr[pixel_index] = color >> 16;
	mlxdata->addr[pixel_index + 1] = color >> 8;
	mlxdata->addr[pixel_index + 2] = color;
}

void	ft_draw_mandelbrot(t_mlxdata *mlxdata, int max_iter)
{
	int			x;
	int			y;
	long double	dx;
	long double	dy;

	mlxdata->max_iter = max_iter;
	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_process_pixel(mlxdata, x, y, dx);
	}
}
