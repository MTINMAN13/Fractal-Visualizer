/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2023/12/29 20:30:42 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_pntf(str);
	exit(EXIT_FAILURE);
}

void	setup_event_hooks(t_mlxdata *mlxdata)
{
	mlx_key_hook(mlxdata->win, key_hook, mlxdata);
	mlx_hook(mlxdata->win, 17, 0, close_window_event, mlxdata); // 17 is the DestroyNotify event (X button)
	mlx_mouse_hook(mlxdata->win, mouse_hook, mlxdata); // Add the mouse hook
}