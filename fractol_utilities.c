/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:31:45 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 02:47:34 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_pntf("error");
	ft_pntf(str);
	ft_pntf("\n\n\n");
	ft_pntf("controls: w, a s d");
	ft_pntf("         : zoom in    -    ;");
	ft_pntf("         : zoom out   -    :");
	ft_pntf("         : Reset      -    -");
	ft_pntf("         : color move -    q, e");
	ft_pntf("         : color mode -    0");
	ft_pntf("thanks, come again");
	exit(EXIT_FAILURE);
}

void	ft_julia_error(void)
{
	ft_pntf("error");
	ft_pntf("Usage GUIDE:     ./fractol julia X Y\n\n");
	ft_pntf("ex.:              x = 0.39, y = 0.6");
	ft_pntf("ex.:              x = -0.6, y = 0.6");
	ft_pntf("ex.:              x = -1.0, y = 0.6\n\n");
	ft_pntf("z_{n+1} = z_{n}^2 + c");
	ft_pntf("thanks, come again");
	exit (EXIT_FAILURE);
}

void	ft_error_check(char *set)
{
	if (ft_strncmp("julia", set, 5) != 0
		&& ft_strncmp("mandelbrot", set, 10) != 0
		&& ft_strncmp("mandeltri", set, 9) != 0
		&& ft_strncmp("ship", set, 4) != 0)
		ft_error("Usage: ./fractol [mandelbrot/julia x y/mandeltri]");
}

double	ft_atoidouble(const char *str)
{
	double	sign;
	double	result;
	double	decimal_place;
	int		i;

	i = 0;
	sign = 1.0;
	result = 0.0;
	decimal_place = 1.0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10.0 + (str[i] - '0');
			decimal_place *= 10.0;
			i++;
		}
	}
	return (sign * result / decimal_place);
}
