/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_shift_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:02:31 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 16:53:50 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_process_color_shift(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 113)
		ft_shift_left(mlxdata);
	else if (keycode == 101)
		ft_shift_right(mlxdata);
}

void	ft_color_switch(t_mlxdata *mlxdata)
{
	if (mlxdata->color_logic == 1)
	{
		mlxdata->color_logic = 2;
	}
	else if (mlxdata->color_logic == 2)
	{
		mlxdata->color_logic = 0;
	}
	else if (mlxdata->color_logic == 0)
	{
		mlxdata->color_logic = 1;
	}
}

void	ft_shift_left(t_mlxdata *mlxdata)
{
	mlxdata->c_offset -= 1;
}

void	ft_shift_right(t_mlxdata *mlxdata)
{
	mlxdata->c_offset += 1;
	printf("zoomvalue : %f\n", mlxdata->zoom);
}
