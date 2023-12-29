/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_aka_key_controls.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:56:45 by mman              #+#    #+#             */
/*   Updated: 2023/12/29 11:11:18 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_mlxdata *mlxdata)
{
	printf("Window Closed\n");
	// ft_cleanup_all(&(vars->img));
	exit(EXIT_SUCCESS);
	return (0);
}

int close_window_event(t_mlxdata *mlxdata)
{
	close_window(mlxdata);
	return (0);
}