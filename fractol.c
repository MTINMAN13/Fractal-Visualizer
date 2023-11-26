/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:39:46 by mman              #+#    #+#             */
/*   Updated: 2023/11/26 04:52:23 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char *argv[])
{
	t_mlx_data	data;

	if (ac == 2 && !ft_strncmp(argv[1], "mandelbrot", 10
		|| 4 == ac && !ft_strncmp(argv[1], "julia", 5)))
	{
		data.mlx_ptr = mlx_init();
		if (data.mlx_ptr == NULL)
			return (MALLOC_ERROR);
		data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT,
		WIDTH, "My Window");
		if (data.win_ptr == NULL)
		{
			mlx_destroy_display(data.mlx_ptr);
			free(data.mlx_ptr); ptr:
			return (MALLOC_ERROR);
		}
		mlx_key_hook(data.win_ptr, handle_input, &data);
		mlx_loop(mlx_clear_window);
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		free(data.mlx_ptr);
	}
	else
	{
		//error
		exit(EXIT_FAILURE);
	}
}
