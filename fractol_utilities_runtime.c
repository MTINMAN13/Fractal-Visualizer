/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities_runtime.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:45:44 by mman              #+#    #+#             */
/*   Updated: 2024/05/12 01:01:29 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_switch(char *set, t_mlxdata *mlxdata, char **argv, int argc)
{
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
}

int	ft_mlx_init(char *set, t_mlxdata *mlxdata, char **argv, int argc)
{
	if (argc == 1)
		ft_error("Usage: ./fractol [mandelbrot/julia x y/mandeltri]");
	ft_error_check(set);
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, set);
	mlxdata->img = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	mlxdata->addr = mlx_get_data_addr(mlxdata->img, &(mlxdata->bits_per_pixel),
			&(mlxdata->line_length), &(mlxdata->endian));
	ft_switch(set, mlxdata, argv, argc);
	return (0);
}

void	ft_cleanup_all(t_mlxdata *mlxdata)
{
	mlx_destroy_image(mlxdata->mlx, mlxdata->img);
	mlx_destroy_window(mlxdata->mlx, mlxdata->win);
	mlx_destroy_display(mlxdata->mlx);
	free(mlxdata->mlx);
	exit(EXIT_SUCCESS);
}
