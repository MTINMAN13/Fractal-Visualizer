/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2024/01/02 19:03:29 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_pntf("error");
	ft_pntf(str);
	ft_pntf("\n\n\n");
	exit(EXIT_FAILURE);
}
void	ft_julia_error(void)
{
	ft_pntf("error");
	ft_pntf("Usage GUIDE:     ./fractol julia X Y\n\n");
	ft_pntf("ex.:              x = -1.0, y = 0.6\n\n");
	ft_pntf("z_{n+1} = z_{n}^2 + c");
	ft_pntf("thanks, come again");
	exit (EXIT_FAILURE);
}