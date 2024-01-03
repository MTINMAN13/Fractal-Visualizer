/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_default_zoom_values.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:43:20 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 15:45:33 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// -2.200800, 3.799200, -1.467200, 2.532800 --- 0.666000
void	ft_default_zoom(t_mlxdata *mlxdata)
{
	mlxdata->zoom = 0.666 * WIDTH / HEIGHT * 0.5;
	mlxdata->min.real = -2.0 * WIDTH / 800.0;
	mlxdata->max.real = 2.0 * WIDTH / 800.0;
	mlxdata->min.imag = -1.0 * HEIGHT / 600.0;
	mlxdata->max.imag = 2.0 * HEIGHT / 600.0;
	mlxdata->center.real = WIDTH / 2;
	mlxdata->center.imag = HEIGHT / 2;
	mlxdata->color_logic = 2;
	mlxdata->c_offset = -121;
}


void	ft_default_zoom_j(t_mlxdata *mlxdata, double real, double imag)
{

	// mlxdata->julia.real = -1.0;
	// mlxdata->julia.imag = 0.6;
	mlxdata->julia.real = real;
	mlxdata->julia.imag = imag;
	mlxdata->zoom = 0.5;
	mlxdata->min.real = -1.00 * WIDTH / 800.0;
	mlxdata->max.real = 3.00 * WIDTH / 800.0;
	mlxdata->min.imag = -0.75 * HEIGHT / 600.0;
	mlxdata->max.imag = 2.25 * HEIGHT / 600.0;
	mlxdata->center.real = WIDTH / 2;
	mlxdata->center.imag = HEIGHT / 2;
	mlxdata->color_logic = 2;
	mlxdata->c_offset = 666;
}

void	ft_default_zoom_mtri(t_mlxdata *mlxdata)
{
	mlxdata->zoom = 0.666;
	mlxdata->min.real = -2.0 * WIDTH / 800.0;
	mlxdata->max.real = 2.0 * WIDTH / 800.0;
	mlxdata->min.imag = -1.0 * HEIGHT / 600.0;
	mlxdata->max.imag = 2.0 * HEIGHT / 600.0;
	mlxdata->center.real = WIDTH / 2;
	mlxdata->center.imag = HEIGHT / 2;
	mlxdata->color_logic = -121;
}