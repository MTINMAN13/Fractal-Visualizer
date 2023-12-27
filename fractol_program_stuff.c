/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_program_stuff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2023/12/27 20:57:41 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_pntf(str);
	exit(1);
}

void	ft_cleanup_all(t_vars vars)
{
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_image(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.img.img_pixels_ptr);

	exit(EXIT_SUCCESS);
}

void	ft_program(t_vars vars)
{
	setup_event_hooks(&vars); // track keys, mouse, window
	ft_do_mandelbrot(&vars);
	mlx_loop(vars.mlx);
}