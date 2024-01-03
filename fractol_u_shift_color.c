/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_shift_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:02:31 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 01:09:49 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_color_switch(t_mlxdata *mlxdata)
{
	if (mlxdata->color_logic == 1)
	{
		mlxdata->color_logic = 2;
		ft_pntf("Switched to color mode 2\n");
	}
	else if (mlxdata->color_logic == 2)
	{
		mlxdata->color_logic = 0;
		ft_pntf("Switched to color mode 0\n");
	}
	else if (mlxdata->color_logic == 0)
	{
		mlxdata->color_logic = 1;
		ft_pntf("Switched to color mode 1\n");
	}
}

void	ft_shift_left(t_mlxdata *mlxdata)
{
	mlxdata->c_offset -= 1;
	ft_pntf("shiftleft %i", mlxdata->c_offset);
}

void	ft_shift_right(t_mlxdata *mlxdata)
{
	mlxdata->c_offset += 1;
	ft_pntf("shiftright");
}
