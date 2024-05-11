/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2024/05/12 00:47:31 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hsl_to_rgb(double h, int *r, int *g, int *b)
{
	double	x;
	double	r_temp;
	double	g_temp;
	double	b_temp;

	x = 0.668 * (1 - fabs(fmod(h / 60.0, 2) - 1));
	r_temp = (0.668 + 0.332) * 255;
	g_temp = (x + 0.332) * 255;
	b_temp = 0.332 * 255;
	apply_correction(&r_temp, 0.332);
	apply_correction(&g_temp, 0.332);
	apply_correction(&b_temp, 0.332);
	*r = (int)r_temp;
	*g = (int)g_temp;
	*b = (int)b_temp;
}

int	calculate_color_zero_component(int r, int g, int b, int i)
{
	int	component;

	if (i == 0)
		component = r;
	else if (i == 1)
		component = g;
	else
		component = b;
	return (component);
}

static void	zero_setter(int *a, int *b, int *c)
{
	a = 0;
	b = 0;
	c = 0;
}

// Function 1
int	ft_calculate_color(int iteration, t_mlxdata *mlxdata, int x, int y)
{
	int		r;
	int		g;
	int		b;

	zero_setter(&r, &g, &b);
	if (iteration == mlxdata->max_iter)
		return (0x000000);
	mlxdata->t = (double)iteration / mlxdata->max_iter;
	if (!(x == WIDTH / 2 && y == HEIGHT / 2))
	{
		if (mlxdata->color_logic == 1)
			calculate_color_logic_1_rgb(mlxdata, &r, &g, &b);
		else if (mlxdata->color_logic == 2)
			calculate_color_logic_2_rgb(mlxdata, &r, &g, &b);
		else if (mlxdata->color_logic == 0)
			return (ft_calculate_color_zero(mlxdata));
	}
	else
	{
		r = (int)(255 * (0.7 + 0.3 * mlxdata->t));
		g = (int)(255 * (0.7 + 0.3 * mlxdata->t));
		b = (int)(255 * (0.7 + 0.3 * mlxdata->t));
	}
	return ((r << 16) | (g << 8) | b);
}

double	ft_influence(t_mlxdata *mlxdata)
{
	if (mlxdata->zoom > 0.3)
		return (1.0);
	else if (mlxdata->zoom > 0.2)
		return (0.5);
	else if (mlxdata->zoom > 0.1 && mlxdata->zoom < 0.2)
		return (0.8);
	else if (mlxdata->zoom > 0.05 && mlxdata->zoom < 0.1)
		return (0.85);
	else if (mlxdata->zoom > 0.01 && mlxdata->zoom < 0.05)
		return (0.95);
	else if (mlxdata->zoom > 0.0003 && mlxdata->zoom < 0.01)
		return (1.2);
	else if (mlxdata->zoom > 0.00004 && mlxdata->zoom < 0.0003)
		return (1.6);
	else if (mlxdata->zoom > 0.0000001 && mlxdata->zoom < 0.00004)
		return (2.0);
	else if (mlxdata->zoom > 0.000000001 && mlxdata->zoom < 0.0000001)
		return (4.0);
	else if (mlxdata->zoom > 0.000000000001 && mlxdata->zoom < 0.000000001)
		return (8.0);
	else if (mlxdata->zoom > 0.000000000000001
		&& mlxdata->zoom < 0.000000000001)
		return (12.0);
	return (15.0);
}
