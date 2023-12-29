/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2023/12/29 11:21:47 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_pntf(str);
	exit(EXIT_FAILURE);
}

int		calculate_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	
	if (iteration == max_iter)
		return (0x000000); // Black for points inside the set
	t = (double)iteration / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	setup_event_hooks(t_mlxdata *mlxdata)
{
	mlx_key_hook(mlxdata->win, key_hook, mlxdata);
	mlx_hook(mlxdata->win, 17, 0, close_window_event, mlxdata); // 17 is the DestroyNotify event (X button)
	mlx_mouse_hook(mlxdata->win, mouse_hook, mlxdata); // Add the mouse hook
}