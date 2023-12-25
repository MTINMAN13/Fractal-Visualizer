
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