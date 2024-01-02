/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:51:19 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 17:25:36 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mouse_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;
	double	x_offset;
	double	y_offset;

	mlxdata->zoom *= zoom_factor;
	move_step = 0.1738 * mlxdata->zoom;
	x_offset = (double)x / (WIDTH / 2);
	y_offset = (double)y / (HEIGHT / 2);
	mlxdata->min.real += move_step * x_offset * WIDTH / 800.0 * 1.2;
	mlxdata->max.real += move_step * x_offset * WIDTH / 800.0 * 1.2;
	mlxdata->min.imag += move_step * y_offset * 1.2;
	mlxdata->max.imag += move_step * y_offset * 1.2;
}

void	ft_mouse_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;
	double	x_offset;
	double	y_offset;

	mlxdata->zoom *= zoom_factor;
	move_step = 0.1738 * mlxdata->zoom;
	x_offset = (double)x / (WIDTH / 1.9);
	y_offset = (double)y / (HEIGHT / 1.9);
	mlxdata->min.real -= move_step * x_offset * WIDTH / 800.0;
	mlxdata->max.real -= move_step * x_offset * WIDTH / 800.0;
	mlxdata->min.imag -= move_step * y_offset * HEIGHT / 700.0;
	mlxdata->max.imag -= move_step * y_offset * HEIGHT / 700.0;
}

int	mouse_hook(int button, int x, int y, t_mlxdata *mlxdata)
{
	if (button == 1 || button == 2)
		return (1);
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	if (button == 4)
		ft_mouse_zoom_out(mlxdata, x, y, 1.1);
	else if (button == 5)
		ft_mouse_zoom_in(mlxdata, x, y, 1.0 / 1.1);
	else if (button == 7)
		mlxdata->zoom += 0.1;
	mlxdata->draw_function(mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

