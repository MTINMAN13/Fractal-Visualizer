/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/23 21:15:26 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    int pixel = mlx_get_color_value(mlx_ptr, color);
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, pixel);
}

int	close_window(void *param)
{
	printf("Window Closed\n");
	(void)param; // Avoid unused parameter warning
	exit(0);
	return (0);
}
int key_press(int keycode, void *param)
{
    t_xvar *mlx_var = (t_xvar *)param; // Cast param to t_xvar pointer
    KeySym keysym = XKeycodeToKeysym(mlx_var->display, keycode, 0);
    ft_pntf("Key Pressed: %d (Keysym: %lu)\n", keycode, (unsigned long)keysym);

    if (keysym == XK_Escape)
    {
        close_window(param);
    }
    return (0);
}

int	main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1400, 600, "Fractol");

    draw_pixel(mlx_ptr, win_ptr, 100, 100, 0xFF0000);

    // Set up event hooks
    mlx_hook(win_ptr, 2, 0, key_press, mlx_ptr);  // 2 is the X key press event
    mlx_hook(win_ptr, 17, 0, close_window, mlx_ptr); // 17 is the DestroyNotify event (X button)

    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);

    return (0);
}
