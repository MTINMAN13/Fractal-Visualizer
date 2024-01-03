/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 15:53:30 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	draw_pixel(t_img *img, int x, int y, int color)
// {
// 	int	offset;

// 	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
// 	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
// }

// int	mandelbrot_iterations(double real, double imag, int max_iterations)
// {
// 	int			iterations;
// 	double		z_real;
// 	double		z_imag;
// 	double		temp_real;
// 	double		temp_imag;

// 	iterations = 0;
// 	z_real = 0.0;
// 	z_imag = 0.0;
// 	while (iterations < max_iterations && (z_real * z_real + z_imag * z_imag) < 4.0)
// 	{
// 		temp_real = z_real * z_real - z_imag * z_imag + real;
// 		temp_imag = 2 * z_real * z_imag + imag;

// 		z_real = temp_real;
// 		z_imag = temp_imag;

// 		iterations++;
// 	}

// 	return (iterations);
// }

// void	ft_do_mandelbrot(t_vars *vars)
// {
// 	int x;
// 	int y;
// 	double real;
// 	double imag;
// 	int iterations;
// 	int color;

// 	y = -1;
// 	while (++y < SIDE_LEN)
// 	{
// 		x = -1;
// 		while (++x < SIDE_LEN)
// 		{
// 			real = RANGE_CHANGE(x, 0, SIDE_LEN - 1, -2.0, 1.0);
// 			imag = RANGE_CHANGE(y, 0, SIDE_LEN - 1, -1.5, 1.5);
// 			iterations = mandelbrot_iterations(real, imag, 100);
// 			if (iterations == 100)
// 				color = 0x000000;
// 			else
// 				color = iterations * 0x001111 + 0x002222;
// 			draw_pixel(&vars->img, x, y, color);
// 		}
// 	}
// }


/////////////////////////////////////////////////////////////////////////
//                              new
///////
//
//
///////////////////////////////////////////////////////////////////////////

int		ft_mandelbrot_iteration(t_complex c, int max_iter)
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wclobbered"

static void ft_process_pixel(register t_mlxdata *mlxdata, register int x, register int y, register long double dx, register long double dy, int max_iter)
{
	t_complex	c;
	int			iter;
	int			color;
	int			pixel_index;			

	c.real = mlxdata->min.real + (long double)x * dx * mlxdata->zoom;
	c.imag = mlxdata->min.imag + (long double)y * dy * mlxdata->zoom;
	iter = ft_mandelbrot_iteration(c, max_iter);
	color = ft_calculate_color(iter, max_iter, mlxdata, x, y);
	pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
	mlxdata->addr[pixel_index] = color >> 16;
	mlxdata->addr[pixel_index + 1] = color >> 8;
	mlxdata->addr[pixel_index + 2] = color;
}

#pragma GCC diagnostic pop

void	ft_draw_mandelbrot(t_mlxdata *mlxdata, int max_iter)
{
	int			x;
	int			y;
	long double	dx;
	long double	dy;

	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_process_pixel(mlxdata, x, y, dx, dy, max_iter);
	}
}