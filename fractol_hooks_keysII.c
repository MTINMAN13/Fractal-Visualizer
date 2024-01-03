/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_keysII.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:28:02 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 18:21:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_assign_julia(t_mlxdata *mlxdata, double real, double imag)
{
	mlxdata->julia.real = real;
	mlxdata->julia.imag = imag;
}

int	ft_process_julia_patterns(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 43)
		ft_assign_julia(mlxdata, 0.285, 0.01);
	else if (keycode == 492)
		ft_assign_julia(mlxdata, -0.3978, 0.62);
	else if (keycode == 441)
		ft_assign_julia(mlxdata, -1.26, 0.05);
	else if (keycode == 488)
		ft_assign_julia(mlxdata, -0.77803, 0.134);
	else if (keycode == 504)
		ft_assign_julia(mlxdata, -0.654760, -0.688200);
	else if (keycode == 105)
		mlxdata->julia.imag += 0.001;
	else if (keycode == 107)
		mlxdata->julia.imag += -0.001;
	else if (keycode == 108)
		mlxdata->julia.real += 0.001;
	else if (keycode == 106)
		mlxdata->julia.real += -0.001;
}

// REAL: -0.792000
// IMAG: 0.156000

void	ft_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;

	move_step = 0.1738 * mlxdata->zoom;
	mlxdata->zoom *= zoom_factor;
	mlxdata->min.real += move_step * WIDTH / 800.0 * 1.05;
	mlxdata->max.real += move_step * WIDTH / 800.0 * 1.05;
	mlxdata->min.imag += move_step * HEIGHT / 700.0 * 0.9;
	mlxdata->max.imag += move_step * HEIGHT / 700.0 * 0.9;
}

void	ft_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;

	move_step = 0.1738 * mlxdata->zoom;
	mlxdata->zoom *= zoom_factor;
	mlxdata->min.real -= move_step * WIDTH / 800.0;
	mlxdata->max.real -= move_step * WIDTH / 800.0;
	mlxdata->min.imag -= move_step * HEIGHT / 800.0 * 0.9;
	mlxdata->max.imag -= move_step * HEIGHT / 800.0 * 0.9;
}

int	ft_key_hook(int keycode, t_mlxdata *mlxdata)
{
	double	move_step;

	move_step = 0.1 * mlxdata->zoom;
	ft_process_movement(keycode, mlxdata, move_step);
	ft_process_other_keys(keycode, mlxdata);
	ft_process_color_shift(keycode, mlxdata);
	ft_process_julia_patterns(keycode, mlxdata);
	mlxdata->draw_function(mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}
