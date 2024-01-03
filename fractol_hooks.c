/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:56:45 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 18:22:20 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_mlxdata *mlxdata)
{
	printf("Window Closed\n");
	ft_cleanup_all(mlxdata);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close_window_event(t_mlxdata *mlxdata)
{
	close_window(mlxdata);
	return (0);
}

void	setup_event_hooks(t_mlxdata *mlxdata)
{
	mlx_key_hook(mlxdata->win, ft_key_hook, mlxdata);
	mlx_hook(mlxdata->win, 17, 0, ft_close_window_event, mlxdata);
	mlx_mouse_hook(mlxdata->win, ft_mouse_hook, mlxdata);
}
