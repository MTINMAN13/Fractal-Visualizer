/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_colooor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:19:05 by mman              #+#    #+#             */
/*   Updated: 2024/05/12 00:51:28 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function 2
int	calculate_color_logic_1(double t, double angle)
{
	double	gradient;
	double	phase_shift;
	int		priority;
	int		i;

	gradient = sin(2 * M_PI * t + angle);
	phase_shift = M_PI / 2;
	priority = 3 % 20;
	i = 0;
	while (i < priority)
	{
		gradient = cos(2 * M_PI * t + phase_shift + angle);
		phase_shift += M_PI / 2;
		i++;
	}
	return ((int)((1 + gradient) * 0.5 * 255));
}

// Function 3
int	calculate_color_logic_2(double t, t_mlxdata *mlxdata)
{
	int	r;
	int	g;
	int	b;

	if (mlxdata->c_offset % 3 == 0)
	{
		r = (int)(7 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(6.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (mlxdata->c_offset % 3 == 1)
	{
		g = (int)(9 * (1 - t) * t * t * t * 255);
		b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		r = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else
	{
		b = (int)(9 * (1 - t) * t * t * t * 255);
		r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	mlxdata->c_offset += OFFSET;
	return (r);
}

// Function 2: Calculate RGB values using color logic 1
void	calculate_color_logic_1_rgb(t_mlxdata *mlxdata, int *r
		, int *g, int *b)
{
	double	angle;

	angle = 2 * M_PI * mlxdata->t + mlxdata->c_offset;
	*r = calculate_color_logic_1(mlxdata->t, angle);
	*g = calculate_color_logic_1(mlxdata->t + 1.0 / 3.0, angle);
	*b = calculate_color_logic_1(mlxdata->t + 2.0 / 3.0, angle);
}

// Function 3: Calculate RGB values using color logic 2
void	calculate_color_logic_2_rgb(t_mlxdata *mlxdata, int *r
		, int *g, int *b)
{
	*r = calculate_color_logic_2(mlxdata->t, mlxdata);
	*g = calculate_color_logic_2(mlxdata->t + 1.0 / 3.0, mlxdata);
	*b = calculate_color_logic_2(mlxdata->t + 2.0 / 3.0, mlxdata);
}

int	ft_calculate_color_zero(t_mlxdata *mlxdata)
{
	int			r;
	int			g;
	int			b;
	int			i;
	int			component;

	mlxdata->result = 0;
	hsl_to_rgb(mlxdata->c_offset + mlxdata->t * 360.0, &r, &g, &b);
	i = (-121 % 16) % 3;
	while (i < 3)
	{
		component = calculate_color_zero_component(r, g, b, i);
		mlxdata->result |= (component << (8 * i));
		i++;
	}
	return (mlxdata->result);
}
