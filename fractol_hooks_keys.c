/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:19 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 15:49:05 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_adjust_render(t_mlxdata *mlxdata, char dir_sign, char real_imag_sign,
		double move_step)
{
	if (dir_sign == '+')
	{
		if (real_imag_sign == 'r')
		{
			mlxdata->min.real += move_step;
			mlxdata->max.real += move_step;
		}
		else if (real_imag_sign == 'i')
		{
			mlxdata->min.imag += move_step;
			mlxdata->max.imag += move_step;
		}
	}
	else if (dir_sign == '-')
	{
		if (real_imag_sign == 'r')
		{
			mlxdata->min.real -= move_step;
			mlxdata->max.real -= move_step;
		}
		else if (real_imag_sign == 'i')
		{
			mlxdata->min.imag -= move_step;
			mlxdata->max.imag -= move_step;
		}
	}
}

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

static void	ft_process_movement(int keycode, t_mlxdata *mlxdata,
	double move_step)
{
	if (keycode == 119)
		ft_adjust_render(mlxdata, '-', 'i', move_step);
	else if (keycode == 97)
		ft_adjust_render(mlxdata, '-', 'r', move_step);
	else if (keycode == 115)
		ft_adjust_render(mlxdata, '+', 'i', move_step);
	else if (keycode == 100)
		ft_adjust_render(mlxdata, '+', 'r', move_step);
}

static void	ft_process_other_keys(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 65307)
		close_window(mlxdata);
	else if (keycode == 505 || keycode == 59 || keycode == 65453)
		ft_zoom_out(mlxdata, WIDTH / 2, HEIGHT / 2, 1.1);
	else if (keycode == 167 || keycode == 39 || keycode == 65451)
		ft_zoom_in(mlxdata, WIDTH / 2, HEIGHT / 2, 1.0 / 1.1);
	else if (keycode == 61)
	{
		if (mlxdata->draw_function == ft_draw_julia)
			ft_default_zoom_j(mlxdata, mlxdata->julia.real,
				mlxdata->julia.imag);
		else if (mlxdata->draw_function == ft_draw_mandelbrot)
			ft_default_zoom(mlxdata);
	}
	else if (keycode == 233 || keycode == 48 || keycode == 65438)
		ft_color_switch(mlxdata);
}

int	key_hook(int keycode, t_mlxdata *mlxdata)
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
