#include "mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct	s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct	s_mlxdata
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	t_complex	min;
	t_complex	max;
}				t_mlxdata;

int		mandelbrot_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		double real_tmp = z.real * z.real - z.imag * z.imag + c.real;
		double imag_tmp = 2 * z.real * z.imag + c.imag;

		z.real = real_tmp;
		z.imag = imag_tmp;

		if (z.real * z.real + z.imag * z.imag > 4)
			break;

		iter++;
	}
	return (iter);
}

int		calculate_color(int iteration, int max_iter)
{
	if (iteration == max_iter)
		return (0x000000); // Black for points inside the set

	double	t = (double)iteration / max_iter;
	int		r = (int)(9 * (1 - t) * t * t * t * 255);
	int		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return ((r << 16) | (g << 8) | b);
}

void	draw_mandelbrot(t_mlxdata *mlxdata, int max_iter)
{
	int		x;
	int		y;
	double	dx;
	double	dy;

	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			t_complex c;
			c.real = mlxdata->min.real + x * dx;
			c.imag = mlxdata->min.imag + y * dy;

			int iter = mandelbrot_iteration(c, max_iter);
			int color = calculate_color(iter, max_iter);

			int pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
			mlxdata->addr[pixel_index] = color >> 16; // Red
			mlxdata->addr[pixel_index + 1] = color >> 8; // Green
			mlxdata->addr[pixel_index + 2] = color; // Blue
		}
	}
}

int		handle_keypress(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69 || keycode == 24)
		mlxdata->zoom *= 1.1;
	else if (keycode == 78 || keycode == 27)
		mlxdata->zoom /= 1.1;
	else if (keycode == 15)
	{
		mlxdata->zoom = 1.0;
		mlxdata->min.real = -2.0;
		mlxdata->max.real = 2.0;
		mlxdata->min.imag = -1.5;
		mlxdata->max.imag = 1.5;
	}

	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_mlxdata mlxdata;

	mlxdata.mlx = mlx_init();
	mlxdata.win = mlx_new_window(mlxdata.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	mlxdata.img = mlx_new_image(mlxdata.mlx, WIDTH, HEIGHT);
	mlxdata.addr = mlx_get_data_addr(mlxdata.img, &mlxdata.bits_per_pixel, &mlxdata.line_length, &mlxdata.endian);

	mlxdata.zoom = 1.0;
	mlxdata.min.real = -2.0;
	mlxdata.max.real = 2.0;
	mlxdata.min.imag = -1.5;
	mlxdata.max.imag = 1.5;

	mlx_hook(mlxdata.win, 2, 1L << 0, handle_keypress, &mlxdata);

	draw_mandelbrot(&mlxdata, 100);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);

	mlx_loop(mlxdata.mlx);
	return (0);
}
