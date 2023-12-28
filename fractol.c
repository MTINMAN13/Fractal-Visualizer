/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/28 20:10:17 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "Fractol");
// 	if (vars.mlx == 0 || vars.win == NULL)
// 		ft_error("exit code");
// 	vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
// 	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);
// 	ft_program(vars);
// 	ft_cleanup_all(vars);
// 	return (0);
// }

int		main(void)
{
	t_mlxdata mlxdata;

	mlxdata.mlx = mlx_init();
	mlxdata.win = mlx_new_window(mlxdata.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	mlxdata.img = mlx_new_image(mlxdata.mlx, WIDTH, HEIGHT);
	mlxdata.addr = mlx_get_data_addr(mlxdata.img, &mlxdata.bits_per_pixel, &mlxdata.line_length, &mlxdata.endian);

	mlxdata.zoom = 1.0;
	mlxdata.min.real = -2.0;
	mlxdata.max.real = 2.0;
	mlxdata.min.imag = -1.5;
	mlxdata.max.imag = 1.5;

	mlx_hook(mlxdata.win, 2, 1L << 0, handle_keypress, &mlxdata); //

	draw_mandelbrot(&mlxdata, 100);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (0);
}
int		handle_keypress(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 24)
		mlxdata->zoom *= 1.1;
	else if (keycode == 78 || keycode == 27)
		mlxdata->zoom /= 1.1;
	else if (keycode == 15)
	{
		mlxdata->zoom = 1.0;
		mlxdata->min.real = -2.0;
		mlxdata->max.real = 2.0;
		mlxdata->min.imag = -1.5;
		mlxdata->max.imag = 1.5;
	}

	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}