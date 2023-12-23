#include "fractol.h"

// int		hook_expose(t_mlx *mlx)
// {
// 	render(mlx);
// 	return (0);
// }

int		die(char *reason)
{
	ft_pntf("hello this is dog yes");
	ft_pntf("okay letsgo");
	ft_putendl_fd(reason, 1);
	return (1);
}

//  LETSGOOOO
// autosave where
// int		main(int argc, char **argv)
// {
// 	t_mlx		*mlx;
// 	t_fractal	*f;

// 	if (argc < 2)
// 		return (die("error: not enough arguments"));
// 	f = fractal_match(argv[1]);
// 	if (f->name == NULL)
// 		return (die("error: invalid fractal name"));
// 	if ((mlx = init(f)) == NULL)
// 		return (die("error: mlx couldn't initialize properly"));
// 	reset_viewport(mlx);
// 	render(mlx);
// 	mlx_key_hook(mlx->window, hook_keydown, mlx);
// 	mlx_expose_hook(mlx->window, hook_expose, mlx);
// 	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
// 	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
// 	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
// 	mlx_loop(mlx->mlx);
// 	return (0);
// }

void *mlx;
void *win1;
void *win2;

int	gere_mouse(int x,int y,int button,void*toto)
{
	ft_printf("Mouse event - new win\n");
	mlx_destroy_window(mlx,win1);
	win1 = mlx_new_window(mlx,random()%500,random()%500,"new win");
	mlx_mouse_hook(win1,gere_mouse,0);
	return (0);
	button = 6;
	(void)toto;
	x = 4;
	y = 3;
}


int	main(void)
{
	srandom(time(0));
	mlx = mlx_init();
	win1 = mlx_new_window(mlx,300,300,"win1");
	win2 = mlx_new_window(mlx,600,600,"win2");
	mlx_mouse_hook(win1,gere_mouse,0);
	mlx_mouse_hook(win2,gere_mouse,0);
	mlx_loop(mlx);
	ft_pntf("i want love and stuff can we cuddle or what");
	return (0);
}
