/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/27 20:44:09 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

int	mandelbrot_iterations(double real, double imag, int max_iterations)
{
	int			iterations;
	double		z_real;
	double		z_imag;
	double		temp_real;
	double		temp_imag;

	iterations = 0;
	z_real = 0.0;
	z_imag = 0.0;
	while (iterations < max_iterations && (z_real * z_real + z_imag * z_imag) < 4.0)
	{
		temp_real = z_real * z_real - z_imag * z_imag + real;
		temp_imag = 2 * z_real * z_imag + imag;

		z_real = temp_real;
		z_imag = temp_imag;

		iterations++;
	}

	return (iterations);
}

void	ft_do_mandelbrot(t_vars *vars)
{
	int x;
	int y;
	double real;
	double imag;
	int iterations;
	int color;

	y = -1;
	while (++y < SIDE_LEN)
	{
		x = -1;
		while (++x < SIDE_LEN)
		{
			real = RANGE_CHANGE(x, 0, SIDE_LEN - 1, -2.0, 1.0);
			imag = RANGE_CHANGE(y, 0, SIDE_LEN - 1, -1.5, 1.5);
			iterations = mandelbrot_iterations(real, imag, 100);
			if (iterations == 100)
				color = 0x000000;
			else
				color = iterations * 0x001111 + 0x002222;
			draw_pixel(&vars->img, x, y, color);
		}
	}
}
