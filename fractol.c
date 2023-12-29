/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2023/12/30 00:56:46 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "Fractol");
// 	if (vars.mlx == 0 || vars.win == NULL)
// 		ft_error("exit code");
// 	vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
// 	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);
// 	ft_program(vars);
// 	ft_cleanup_all(vars);
// 	return (0);
// }

#include "fractol.h"





void	ft_adjust_render(t_mlxdata *mlxdata, char dir_sign, char real_imag_sign, double move_step)
{
	if (dir_sign == '+')
	{
		if (real_imag_sign == 'r')
		{
			mlxdata->min.real += move_step;
			mlxdata->max.real += move_step;
		}
		else if (real_imag_sign == 'i')
		{
			mlxdata->min.imag += move_step;
			mlxdata->max.imag += move_step;
		}
	}
	else if (dir_sign == '-')
	{
		if (real_imag_sign == 'r')
		{
			mlxdata->min.real -= move_step;
			mlxdata->max.real -= move_step;
		}
		else if (real_imag_sign == 'i')
		{
			mlxdata->min.imag -= move_step;
			mlxdata->max.imag -= move_step;
		}
	}
}

void	ft_color_switch(t_mlxdata *mlxdata)
{
	if (mlxdata->color_logic == 1)
	{
		mlxdata->color_logic = 2;
		ft_pntf("Switched to color mode 2\n");
	}
	else
	{
		mlxdata->color_logic = 1;
		ft_pntf("Switched to color mode 1\n");
	}
}
void ft_adjust_zoom(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
    double center_real = mlxdata->min.real + x / (double)WIDTH * (mlxdata->max.real - mlxdata->min.real);
    double center_imag = mlxdata->min.imag + y / (double)HEIGHT * (mlxdata->max.imag - mlxdata->min.imag);

    mlxdata->min.real = center_real - (mlxdata->max.real - mlxdata->min.real) / (2 * zoom_factor);
    mlxdata->max.real = center_real + (mlxdata->max.real - mlxdata->min.real) / (2 * zoom_factor);
    mlxdata->min.imag = center_imag - (mlxdata->max.imag - mlxdata->min.imag) / (2 * zoom_factor);
    mlxdata->max.imag = center_imag + (mlxdata->max.imag - mlxdata->min.imag) / (2 * zoom_factor);
}



void ft_zoomies(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
    mlxdata->zoom *= zoom_factor;
    ft_adjust_zoom(mlxdata, x, y, 1.0 / zoom_factor);
}

int	key_hook(int keycode, t_mlxdata *mlxdata)
{
	ft_pntf("Hello from key_hook * %i!", keycode);
	double move_step = 0.1 * mlxdata->zoom; // Calculate the proportional movement step
	if (keycode == 65307) // 65307 is the keycode for the ESC key
		close_window(mlxdata);
	else if (keycode == 505) // ; (ZOOM OUT)
        ft_zoomies(mlxdata, WIDTH / 2, HEIGHT / 2, 1.1);
	else if (keycode == 167) // : (ZOOM IN)
        ft_zoomies(mlxdata, WIDTH / 2, HEIGHT / 2, 1.0 / 1.1);
	else if (keycode == 61) // - (RESET)
		ft_default_zoom(mlxdata);
	else if (keycode == 119) // W (move up)
		ft_adjust_render(mlxdata, '-', 'i', move_step);
	else if (keycode == 97) // A (move left)
		ft_adjust_render(mlxdata, '-', 'r', move_step);
	else if (keycode == 115) // S (move down)
		ft_adjust_render(mlxdata, '+', 'i', move_step);
	else if (keycode == 100) // D (move right)
		ft_adjust_render(mlxdata, '+', 'r', move_step);
	else if (keycode == 0)
		ft_pntf("REAL: %i \nIMAG: %i \nZOOM; %i", mlxdata->min.real, mlxdata->max.imag, mlxdata->zoom);
	else if (keycode == 233) // Key with code 233 (adjust as needed)
		ft_color_switch(mlxdata);
	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

// ... (rest of the code remains unchanged)


int	mouse_hook(int button, int x, int y, t_mlxdata *mlxdata)
{
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	// Add your mouse event handling logic here
	if (button == 4)
		mlxdata->zoom /= 1.04;
	draw_mandelbrot(mlxdata, 100);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

int		mandelbrot_iteration(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;
	double		real_tmp;
	double		imag_tmp;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		real_tmp = z.real * z.real - z.imag * z.imag + c.real;
		imag_tmp = 2 * z.real * z.imag + c.imag;
		z.real = real_tmp;
		z.imag = imag_tmp;
		if (z.real * z.real + z.imag * z.imag > 4)
			break;
		iter++;
	}
	return (iter);
}

static void process_pixel(t_mlxdata *mlxdata, int x, int y, double dx, double dy, int max_iter)
{
    // Adjust the calculation of c to take into account the zoom factor
    t_complex c;
    int iter;
    int color;
    int pixel_index;

    c.real = mlxdata->min.real + x * dx * mlxdata->zoom;
    c.imag = mlxdata->min.imag + y * dy * mlxdata->zoom;

    iter = mandelbrot_iteration(c, max_iter);
    color = calculate_color(iter, max_iter, mlxdata->color_logic, x, y);
    pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
    mlxdata->addr[pixel_index] = color >> 16;     // Red
    mlxdata->addr[pixel_index + 1] = color >> 8;  // Green
    mlxdata->addr[pixel_index + 2] = color;       // Blue
}


void		draw_mandelbrot(t_mlxdata *mlxdata, int max_iter)
{
	int			x;
	int			y;
	double		dx;
	double		dy;

	dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
	dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			process_pixel(mlxdata, x, y, dx, dy, max_iter);
	}
}


void calculate_smooth_color(double angle, int *r, int *g, int *b)
{
    // Use HSL color space for smoother transitions
    double hue = fmod(angle / (2 * M_PI), 1.0); // Normalize angle to [0, 1)
    double saturation = 1.0; // Full saturation
    double lightness = 0.5;  // Adjust the lightness as needed

    double chroma = (1 - fabs(2 * lightness - 1)) * saturation;
    double hue_ = 6 * hue;
    double x = chroma * (1 - fabs(fmod(hue_, 2) - 1));

    double r_, g_, b_;
    if (hue_ >= 0 && hue_ < 1)
    {
        r_ = chroma;
        g_ = x;
        b_ = 0;
    }
    else if (hue_ >= 1 && hue_ < 2)
    {
        r_ = x;
        g_ = chroma;
        b_ = 0;
    }
    else if (hue_ >= 2 && hue_ < 3)
    {
        r_ = 0;
        g_ = chroma;
        b_ = x;
    }
    else if (hue_ >= 3 && hue_ < 4)
    {
        r_ = 0;
        g_ = x;
        b_ = chroma;
    }
    else if (hue_ >= 4 && hue_ < 5)
    {
        r_ = x;
        g_ = 0;
        b_ = chroma;
    }
    else
    {
        r_ = chroma;
        g_ = 0;
        b_ = x;
    }

    double m = lightness - chroma / 2;
    *r = (int)((r_ + m) * 255);
    *g = (int)((g_ + m) * 255);
    *b = (int)((b_ + m) * 255);
}

int calculate_color(int iteration, int max_iter, int color_logic, int x, int y)
{
    double t = (double)iteration / max_iter;

    if (iteration == max_iter)
        return 0x000000; // Black for points inside the set

    double angle = 2 * M_PI * t; // Convert t to radians for sine function
    int r, g, b;

    if (x == WIDTH / 2 && y == HEIGHT / 2)
    {
        // For the very middle pixel, make it 30% lighter
        r = g = b = (int)(255 * (0.7 + 0.3 * t));
    }
    else if (color_logic == 1)
    {
        // Your existing color logic 1
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
    else if (color_logic == 2)
    {
        // Smooth color transition for color logic 2
        calculate_smooth_color(angle, &r, &g, &b);
    }
    else
    {
        // Handle unexpected input (optional)
        return 0x000000;
    }

    return (r << 16) | (g << 8) | b;
}



void	ft_default_zoom(t_mlxdata *mlxdata)
{
	mlxdata->zoom = 0.5;
	mlxdata->min.real = -2.0;
	mlxdata->max.real = 2.0;
	mlxdata->min.imag = -1.5;
	mlxdata->max.imag = 1.5;
	mlxdata->center.real = WIDTH / 2;
	mlxdata->center.imag = HEIGHT / 2;
	mlxdata->color_logic = 1;
}

void	ft_mlx_init(char *set, t_mlxdata *mlxdata)
{
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, set);
	mlxdata->img = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	mlxdata->addr = mlx_get_data_addr(mlxdata->img, &(mlxdata->bits_per_pixel), &(mlxdata->line_length), &(mlxdata->endian));
	ft_default_zoom(mlxdata);
}

int		main(void)
{
	t_mlxdata mlxdata;

	ft_mlx_init("Mandelbrot Set", &mlxdata);
	// mlx_hook(mlxdata.win, 2, 1L << 0, handle_keypress, &mlxdata); //

	draw_mandelbrot(&mlxdata, 100);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (0);
}