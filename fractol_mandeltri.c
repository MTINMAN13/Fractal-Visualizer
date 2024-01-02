/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandeltri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:00:54 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 15:26:04 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z^2 + c^0.2

int		mandelbrot_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		real_tmp;
	double		imag_tmp;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		real_tmp = z.real * z.real - z.imag * z.imag + pow(c.real, 0.2);
		imag_tmp = 2 * z.real * z.imag + pow(c.imag, 0.2);
		z.real = real_tmp;
		z.imag = imag_tmp;
		if (z.real * z.real + z.imag * z.imag > 4)
			break;
		iter++;
	}
	return (iter);
}

