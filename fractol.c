/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 02:50:16 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*                   T O D O                                                     .
- MEMORY LEAKS
- COPY SOMEONES (freeware) RGB LOGIC
(remove comments, statements, formatting)
// wuki edge of seventeen
*/

int	ft_mlx_init(char *set, t_mlxdata *mlxdata, char **argv, int argc)
{
	ft_error_check(set);
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, set);
	mlxdata->img = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	mlxdata->addr = mlx_get_data_addr(mlxdata->img, &(mlxdata->bits_per_pixel),
			&(mlxdata->line_length), &(mlxdata->endian));
	if (ft_strncmp(set, "mandelbrot", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = ft_draw_mandelbrot;
		ft_default_zoom(mlxdata);
	}
	else if (ft_strncmp(set, "julia", ft_strlen(set)) == 0)
	{
		if (argc <= 2)
			ft_julia_error();
		mlxdata->draw_function = ft_draw_julia;
		mlxdata->julia.real = ft_atoidouble(argv[2]);
		mlxdata->julia.imag = ft_atoidouble(argv[3]);
		ft_default_zoom_j(mlxdata, mlxdata->julia.real, mlxdata->julia.imag);
	}
	else if (ft_strncmp(set, "mandeltri", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = ft_draw_mandelbar;
		ft_default_zoom(mlxdata);
	}
	else if (ft_strncmp(set, "ship", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = ft_draw_burning_ship;
		ft_default_zoom(mlxdata);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	ft_mlx_init(argv[1], &mlxdata, argv, argc);
	mlxdata.draw_function(&mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (EXIT_SUCCESS);
}
