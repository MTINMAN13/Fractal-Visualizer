/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:19 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 17:00:18 by mman             ###   ########.fr       */
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

void	ft_process_movement(int keycode, t_mlxdata *mlxdata, double move_step)
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

void	ft_process_other_keys(int keycode, t_mlxdata *mlxdata)
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
