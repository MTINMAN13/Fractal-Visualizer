/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/26 00:33:35 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	// Set up event hooks
	setup_event_hooks(&vars);

    ft_do_mandelbrot(&vars);
	draw_pixel(&vars, 100, 100, 0xFF0000);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);

	return (0);
}

void    ft_do_mandelbrot(t_vars *vars)
{
    
}