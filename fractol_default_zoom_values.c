/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_default_zoom_values.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:43:20 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 15:50:35 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_default_zoom(t_mlxdata *mlxdata)
{
    mlxdata->zoom = 0.666;
    mlxdata->min.real = -2.0 * WIDTH / 800.0;   // Adjust the divisor based on your actual WIDTH
    mlxdata->max.real = 2.0 * WIDTH / 800.0;    // Adjust the divisor based on your actual WIDTH
    mlxdata->min.imag = -1.5 * HEIGHT / 600.0;  // Adjust the divisor based on your actual HEIGHT
    mlxdata->max.imag = 1.5 * HEIGHT / 600.0;   // Adjust the divisor based on your actual HEIGHT
    mlxdata->center.real = WIDTH / 2;
    mlxdata->center.imag = HEIGHT / 2;
    mlxdata->color_logic = 1;
}


void ft_default_zoom_j(t_mlxdata *mlxdata)
{
    mlxdata->zoom = 1.178974;
    mlxdata->min.real = -2.5 * WIDTH / 800.0;   // Adjust the divisor based on your actual WIDTH
    mlxdata->max.real = 1.5 * WIDTH / 800.0;    // Adjust the divisor based on your actual WIDTH
    mlxdata->min.imag = -1.75 * HEIGHT / 600.0; // Adjust the divisor based on your actual HEIGHT
    mlxdata->max.imag = 1.25 * HEIGHT / 600.0;  // Adjust the divisor based on your actual HEIGHT
    mlxdata->center.real = WIDTH / 2;
    mlxdata->center.imag = HEIGHT / 2;
    mlxdata->color_logic = 1;
}