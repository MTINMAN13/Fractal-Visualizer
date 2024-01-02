/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_shift_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:02:31 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 22:13:33 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
