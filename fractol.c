/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/26 00:13:10 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook * %i!\n", keycode);
    if (keycode == 65307)
        close_window(keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	// Add your mouse event handling logic here
	return (0);
}

void	setup_event_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window_event, vars); // 17 is the DestroyNotify event (X button)
	mlx_mouse_hook(vars->win, mouse_hook, vars); // Add the mouse hook
}

void	draw_pixel(t_vars *vars, int x, int y, int color)
{
	int pixel;

	pixel = mlx_get_color_value(vars->mlx, color);
	mlx_pixel_put(vars->mlx, vars->win, x, y, pixel);
}

int	close_window(void *param)
{
	printf("Window Closed\n");
	(void)param;
	exit(0);
	return (0);
}

int	close_window_event(int keycode, t_vars *vars)
{
	if (keycode == 17) // 17 is the keycode for the DestroyNotify event (X button press)
		close_window(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");

	// Set up event hooks
	setup_event_hooks(&vars);

	draw_pixel(&vars, 100, 100, 0xFF0000);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);

	return (0);
}
