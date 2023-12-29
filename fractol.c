/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/29 11:45:55 by mman             ###   ########.fr       */
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

void	ft_default_zoom(t_mlxdata *mlxdata)
{
	mlxdata->zoom = 1.0;
	mlxdata->min.real = -2.0;
	mlxdata->max.real = 2.0;
	mlxdata->min.imag = -1.5;
	mlxdata->max.imag = 1.5;
}

void	ft_mlx_init(char *set, t_mlxdata *mlxdata)
{
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, set);
	mlxdata->img = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	mlxdata->addr = mlx_get_data_addr(mlxdata->img, &(mlxdata->bits_per_pixel), &(mlxdata->line_length), &(mlxdata->endian));
	ft_default_zoom(mlxdata);
}

int		main(void)
{
	t_mlxdata mlxdata;

	ft_mlx_init("Mandelbrot Set", &mlxdata);
	// mlx_hook(mlxdata.win, 2, 1L << 0, handle_keypress, &mlxdata); //

	draw_mandelbrot(&mlxdata, 100);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (0);
}

int	key_hook(int keycode, t_mlxdata *mlxdata)
{
	ft_pntf("Hello from key_hook * %i!", keycode);
	if (keycode == 65307) // 65307 is the keycode for the ESC key
		close_window(mlxdata);
	else if (keycode == 505) // ; (ZOOM OUT)
		mlxdata->zoom *= 1.1;
	else if (keycode == 167) // : (ZOOM IN)
		mlxdata->zoom /= 1.1;
	else if (keycode == 61) // - (RESET)
	{
		ft_default_zoom(mlxdata);
	}
	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlxdata *mlxdata)
{
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	// Add your mouse event handling logic here
	if (button == 4)
		mlxdata->zoom /= 1.04;
	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}