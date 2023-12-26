

#include "fractol.h"

void	draw_pixel(t_vars *vars, int x, int y, int color)
{
	int pixel;

	pixel = mlx_get_color_value(vars->mlx, color);
	mlx_pixel_put(vars->mlx, vars->win, x, y, pixel);
}