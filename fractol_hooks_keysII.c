/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_keysII.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:28:02 by mman              #+#    #+#             */
/*   Updated: 2024/01/08 18:46:45 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_assign_julia(t_mlxdata *mlxdata, double real, double imag)
{
	mlxdata->julia.real = real;
	mlxdata->julia.imag = imag;
}

int	ft_process_julia_patterns(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 43 || keycode == 49)
		ft_assign_julia(mlxdata, 0.285, 0.01);
	else if (keycode == 492 || keycode == 50) // 2
		ft_assign_julia(mlxdata, -0.3978, 0.62);
	else if (keycode == 441 || keycode == 51) // 3
		ft_assign_julia(mlxdata, -1.26, 0.05);
	else if (keycode == 488 || keycode == 52) // 4
		ft_assign_julia(mlxdata, -0.77803, 0.134);
	else if (keycode == 504 || keycode == 53) // 5
		ft_assign_julia(mlxdata, -0.654760, -0.688200);
	else if (keycode == 105) // i
		mlxdata->julia.imag+= 0.001;
	else if (keycode == 107) // k
		mlxdata->julia.imag += -0.001;
	else if (keycode == 108) // l
		mlxdata->julia.real += 0.001;
	else if (keycode == 106) // j
		mlxdata->julia.real += -0.001;
}

// REAL: -0.792000
// IMAG: 0.156000
