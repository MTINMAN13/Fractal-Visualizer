/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/23 20:48:44 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Window");

    mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFF0000);
    mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, 0x00FF00);
    mlx_pixel_put(mlx_ptr, win_ptr, 300, 300, 0x0000FF);

    mlx_loop(mlx_ptr);

    return (0);
}
