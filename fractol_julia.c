/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:46:12 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 19:42:41 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_julia_iteration(t_complex z, t_complex c, int max_iter)
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
			break;
		iter++;
	}
	return (iter);
}

static t_complex ft_compute_julia_c(t_mlxdata *mlxdata, int x, double dx, int y, double dy)
{
    t_complex c;
    c.real = mlxdata->min.real + (double)x * dx * mlxdata->zoom;
    c.imag = mlxdata->min.imag + (double)y * dy * mlxdata->zoom;
    return c;
}

static void	ft_draw_single_pixel(t_mlxdata *mlxdata, int x, int y, double dx, double dy, int max_iter)
{
    t_complex 	z;
    int 		iter;
    int 		color;
    int 		pixel_index;

    z.real = mlxdata->min.real + (double)x * dx * mlxdata->zoom;
    z.imag = mlxdata->min.imag + (double)y * dy * mlxdata->zoom;
    iter = ft_julia_iteration(z, mlxdata->julia, max_iter);
    color = ft_calculate_color(iter, max_iter, mlxdata->color_logic, x, y);
    pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
    mlxdata->addr[pixel_index] = color >> 16;     // Red
    mlxdata->addr[pixel_index + 1] = color >> 8;  // Green
    mlxdata->addr[pixel_index + 2] = color;       // Blue
}

void ft_draw_julia(t_mlxdata *mlxdata, int max_iter)
{
	int		x;
	int		y;
	double	dx;
	double	dy;

	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			t_complex c = ft_compute_julia_c(mlxdata, x, dx, y, dy);
			ft_draw_single_pixel(mlxdata, x, y, dx, dy, max_iter);
		}
	}
}



// .                              OLD                                        .
//
//
//                                                                            .

// void ft_draw_julia(t_mlxdata *mlxdata, int max_iter)
// {
//     int x;
//     int y;
//     double dx;
//     double dy;

//     dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
//     dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
//     y = -1;
//     while (++y < HEIGHT)
//     {
//         x = -1;
//         while (++x < WIDTH)
//             ft_process_julia_pixel(mlxdata, x, y, dx, dy, max_iter);
//     }
// }

// void ft_process_julia_pixel(t_mlxdata *mlxdata, int x, int y, double dx, double dy, int max_iter)
// {
//     t_complex c;
//     t_complex z;
//     int iter;
//     int color;
//     int pixel_index;

//     // Adjust the calculation of c to take into account the zoom factor
//     c.real = mlxdata->min.real + x * dx * mlxdata->zoom;
//     c.imag = mlxdata->min.imag + y * dy * mlxdata->zoom;
// 	z.real = (double)x / WIDTH * 3.0 - 1.5; // Adjust these values as needed
// 	z.imag = (double)y / HEIGHT * 3.0 - 1.5;

// 	iter = ft_julia_iteration(c, z, max_iter);
// 	color = ft_calculate_color(iter, max_iter, mlxdata->color_logic, x, y);
// 	pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
// 	mlxdata->addr[pixel_index] = color >> 16;     // Red
// 	mlxdata->addr[pixel_index + 1] = color >> 8;  // Green
// 	mlxdata->addr[pixel_index + 2] = color;       // Blue
// }

// int	ft_julia_iteration(t_complex c, t_complex z, int max_iter)
// {
// 	int			iter;
// 	double		real_tmp;
// 	double		imag_tmp;

// 	iter = 0;
// 	while (iter < max_iter)
// 	{
// 		real_tmp = z.real * z.real - z.imag * z.imag + c.real;
// 		imag_tmp = 2 * z.real * z.imag + c.imag;
// 		z.real = real_tmp;
// 		z.imag = imag_tmp;
// 		if (z.real * z.real + z.imag * z.imag > 4)
// 			break;
// 		iter++;
// 	}
// 	return (iter);
// }