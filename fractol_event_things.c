

#include "fractol.h"


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

void	draw_pixel(t_vars *vars, int x, int y, int color)
{
	int pixel;

	pixel = mlx_get_color_value(vars->mlx, color);
	mlx_pixel_put(vars->mlx, vars->win, x, y, pixel);
}