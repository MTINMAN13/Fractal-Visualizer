/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:19 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 16:02:13 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;

	move_step = 0.1738 * mlxdata->zoom; // Calculate the proportional movement step
	mlxdata->zoom *= zoom_factor;
	mlxdata->min.real += move_step * WIDTH / 800.0;
	mlxdata->max.real += move_step * WIDTH / 800.0;
	mlxdata->min.imag += move_step * HEIGHT / 700.0;
	mlxdata->max.imag += move_step * HEIGHT / 700.0;
}

void ft_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;

	move_step = 0.1738 * mlxdata->zoom; // Calculate the proportional movement step
	mlxdata->zoom *= zoom_factor;
	mlxdata->min.real -= move_step * WIDTH / 800.0;
	mlxdata->max.real -= move_step * WIDTH / 800.0;
	mlxdata->min.imag -= move_step * HEIGHT / 800.0;
	mlxdata->max.imag -= move_step * HEIGHT / 800.0;
}


int	key_hook(int keycode, t_mlxdata *mlxdata)
{
	ft_pntf("Hello from key_hook * %i!", keycode);
	double	move_step;

	move_step = 0.1 * mlxdata->zoom; // Calculate the proportional movement step
	if (keycode == 65307) // 65307 is the keycode for the ESC key
		close_window(mlxdata);
	else if (keycode == 505 || keycode == 59 || keycode == 65453) // ; (ZOOM OUT)
		ft_zoom_out(mlxdata, WIDTH / 2, HEIGHT / 2, 1.1);
	else if (keycode == 167 || keycode == 39 || keycode == 65451) // : (ZOOM IN)
		ft_zoom_in(mlxdata, WIDTH / 2, HEIGHT / 2, 1.0 / 1.1);
	else if (keycode == 61) // - (RESET)
		ft_default_zoom(mlxdata);
	else if (keycode == 119) // W (move up)
		ft_adjust_render(mlxdata, '-', 'i', move_step);
	else if (keycode == 97) // A (move left)
		ft_adjust_render(mlxdata, '-', 'r', move_step);
	else if (keycode == 115) // S (move down)
		ft_adjust_render(mlxdata, '+', 'i', move_step);
	else if (keycode == 100) // D (move right)
		ft_adjust_render(mlxdata, '+', 'r', move_step);
	else if (keycode == 0)
		ft_pntf("REAL: %i \nIMAG: %i \nZOOM; %i", mlxdata->min.real, mlxdata->max.imag, mlxdata->zoom);
	else if (keycode == 233 || keycode == 48 || keycode == 65438) // Key with code 233 (adjust as needed)
		ft_color_switch(mlxdata);
	mlxdata->draw_function(mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}