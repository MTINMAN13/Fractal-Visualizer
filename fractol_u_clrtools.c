/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_u_clrtools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:15:07 by mman              #+#    #+#             */
/*   Updated: 2024/05/12 00:51:02 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to convert HSL to RGB
void	calculate_hsl(double *s, double *l)
{
	*s = 1.0;
	*l = 0.666;
}

double	calculate_c(double s, double l)
{
	return ((1 - fabs(2 * l - 1)) * s);
}

double	calculate_x(double c, double h)
{
	return (c * (1 - fabs(fmod(h / 60.0, 2) - 1)));
}

double	calculate_m(double l, double c)
{
	return (l - c / 2.0);
}

void	apply_correction(double *component, double m)
{
	*component = (*component + m) * 255;
}
