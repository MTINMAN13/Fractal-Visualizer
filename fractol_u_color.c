/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 00:26:15 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_switch(t_mlxdata *mlxdata)
{
	if (mlxdata->color_logic == 1)
	{
		mlxdata->color_logic = 2;
		ft_pntf("Switched to color mode 2\n");
	}
	else if (mlxdata->color_logic == 2)
	{
		mlxdata->color_logic = 1;
		ft_pntf("Switched to color mode 1\n");
	}
	printf("%f, %f, %f, %f --- %f\n", mlxdata->min.real, mlxdata->max.real, mlxdata->min.imag, mlxdata->max.imag, mlxdata->zoom);
	// -0.845634, 3.154366, -0.345634, 2.654366 --- 0.001808
	// -0.842690, 3.157310, 0.190110, 3.190110 --- 0.000114
	// mlxdata->min.real, mlxdata->max.real, mlxdata->min.imag, mlxdata->max.imag, mlxdata->zoom
}

// #include <math.h>

// void calculate_smooth_color_two(double angle, int *r, int *g, int *b, int max_iter)
// {
//     // Modified color logic with additional hues for a smoother loop back to the initial color
//     double t = angle / (2 * M_PI);

//     // Use a sinusoidal function to create a smooth loop back
//     double modulation = 0.5 + 0.5 * sin((t + 0.5) * M_PI);

//     // Adjust t with the modulation factor to control the loop frequency
//     t = fmod(t + 0.5 * modulation, 1.0);

//     *r = (int)(9 * (1 - t) * t * t * t * 255);
//     *g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     *b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

//     // Additional hues for a more varied color palette
//     int lila_r = (int)(8.5 * (1 - t) * (1 - t) * t * t * 255);
//     int lila_g = (int)(9 * (1 - t) * t * t * t * 255);
//     int lila_b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);

//     int orange_r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int orange_g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//     int orange_b = (int)(9 * (1 - t) * t * t * t * 255);

//     // Blend the additional hues with the primary color based on the iteration count
//     double blend_factor = (double)max_iter / 100.0; // Adjust as needed
//     *r = (int)((1 - blend_factor) * *r + blend_factor * lila_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * lila_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * lila_b);

//     // You can add more blending with other hues here based on the iteration count
//     // For example, blend with orange based on the iteration count
//     *r = (int)((1 - blend_factor) * *r + blend_factor * orange_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * orange_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * orange_b);
// }



int ft_calculate_color(int iteration, int max_iter, t_mlxdata *mlxdata, int x, int y)
{
	double t = (double)iteration / max_iter;
	double angle;
	int r, g, b;
	int offset;
	int priority;
	double t_squared;
	double t_cubed;
	double gradient;
	double phase_shift;
	int i;
	int r_component, g_component, b_component;

	if (iteration == max_iter)
		return 0x000000;

	angle = 2 * M_PI * t;
	r = g = b = 0;

	if (x == WIDTH / 2 && y == HEIGHT / 2)
	{
		r = g = b = (int)(255 * (0.7 + 0.3 * t));
	}
	else if (mlxdata->color_logic == 1)
	{
		offset = mlxdata->c_offset;
		priority = 3 % 20;
		t_squared = t * t;
		t_cubed = t_squared * t;
		gradient = sin(2 * M_PI * t);
		phase_shift = M_PI / 2;
		i = 0;

		while (i < priority)
		{
			double temp = gradient;
			gradient = cos(2 * M_PI * t + phase_shift);
			phase_shift += M_PI / 2;
			i++;
		}

		r = (int)((1 + gradient) * 0.5 * 255);
		g = (int)((1 + sin(2 * M_PI * t + phase_shift)) * 0.5 * 255);
		b = (int)((1 + cos(2 * M_PI * t + phase_shift)) * 0.5 * 255);
	}
	else if (mlxdata->color_logic == 2)
	{
		offset = mlxdata->c_offset;
		priority = (offset % 3);
		r_component = (int)(9 * (1 - t) * t * t * t * 255);
		g_component = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b_component = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

		if (priority == 0)
		{
			r = r_component;
			g = g_component;
			b = b_component;
		}
		else if (priority == 1)
		{
			r = g_component;
			g = b_component;
			b = r_component;
		}
		else
		{
			r = b_component;
			g = r_component;
			b = g_component;
		}
	}
	else
	{
		return 0x000000;
	}

	return (r << 16) | (g << 8) | b;
}
