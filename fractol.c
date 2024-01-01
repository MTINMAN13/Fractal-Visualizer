/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/01 23:31:05 by mman             ###   ########.fr       */
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

/*                   B O N U S                                                     .
One more different fractal (more than a hundred different types of fractals are
referenced online).
• The zoom follows the actual mouse position. ✅
• In addition to the zoom: moving the view by pressing the arrows keys. ✅
• Make the color range shift.
                                                                                  .
*//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/01 21:52:52 by mman             ###   ########.fr       */
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

/*                   B O N U S                                                     .
One more different fractal (more than a hundred different types of fractals are
referenced online).
• The zoom follows the actual mouse position. ✅
• In addition to the zoom: moving the view by pressing the arrows keys. ✅
• Make the color range shift.
                                                                                  .
*/


/*                   T O D O                                                     .
mouse 4 and 5 zoom in and out ✅
Your program must offer the Julia set and the Mandelbrot set.
You must be able to create different Julia sets by passing different parameters to
the program.
A parameter is passed on the command line to define what type of fractal will be
displayed in a window.
◦ You can handle more parameters to use them as rendering options.
◦ If no parameter is provided, or if the parameter is invalid, the program displays
a list of available parameters and exits properly.
solve leaks in memory
                                                                                  .
*/
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
	printf("%f, %f, %f, %f --- %f\n", mlxdata->min.real, mlxdata->max.real, mlxdata->min.imag, mlxdata->max.imag, mlxdata->zoom);
	// -0.845634, 3.154366, -0.345634, 2.654366 --- 0.001808
	// -0.842690, 3.157310, 0.190110, 3.190110 --- 0.000114
	// mlxdata->min.real, mlxdata->max.real, mlxdata->min.imag, mlxdata->max.imag, mlxdata->zoom
}

void ft_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	mlxdata->zoom *= zoom_factor;
	double move_step = 0.1738 * mlxdata->zoom; // Calculate the proportional movement step
	mlxdata->min.real += move_step;
	mlxdata->max.real += move_step;
	mlxdata->min.imag += move_step;
	mlxdata->max.imag += move_step;
}

void ft_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	mlxdata->zoom *= zoom_factor;
	double move_step = 0.1738 * mlxdata->zoom; // Calculate the proportional movement step
	mlxdata->min.real -= move_step;
	mlxdata->max.real -= move_step;
	mlxdata->min.imag -= move_step;
	mlxdata->max.imag -= move_step;
}


int	key_hook(int keycode, t_mlxdata *mlxdata)
{
	ft_pntf("Hello from key_hook * %i!", keycode);
	double move_step = 0.1 * mlxdata->zoom; // Calculate the proportional movement step
	if (keycode == 65307) // 65307 is the keycode for the ESC key
		close_window(mlxdata);
	else if (keycode == 505 || keycode == 59 || keycode == 65453) // ; (ZOOM OUT)
        ft_zoom_out(mlxdata, WIDTH / 2, HEIGHT / 2, 1.1);
	else if (keycode == 167 || keycode == 39 || keycode == 65451) // : (ZOOM IN)
        ft_zoom_in(mlxdata, WIDTH / 2, HEIGHT / 2, 1.0 / 1.1);
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
	else if (keycode == 233 || keycode == 48 || keycode == 65438) // Key with code 233 (adjust as needed)
		ft_color_switch(mlxdata);
    mlxdata->draw_function(mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img, 0, 0);
	return (0);
}

// ... (rest of the code remains unchanged)

void	ft_mouse_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double move_step;
	double x_offset;
	double y_offset;

	mlxdata->zoom *= zoom_factor;
	move_step = 0.1738 * mlxdata->zoom;
	x_offset = (double)x / (WIDTH / 2);
	y_offset = (double)y / (HEIGHT / 2);
	mlxdata->min.real += move_step * x_offset;
	mlxdata->max.real += move_step * x_offset;
	mlxdata->min.imag += move_step * y_offset;
	mlxdata->max.imag += move_step * y_offset;
}

void	ft_mouse_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor)
{
	double	move_step;
	double	x_offset;
	double	y_offset;

	mlxdata->zoom *= zoom_factor;
	move_step = 0.1738 * mlxdata->zoom;
	x_offset = (double)x / (WIDTH / 1.9);
	y_offset = (double)y / (HEIGHT / 1.9);
	mlxdata->min.real -= move_step * x_offset;
	mlxdata->max.real -= move_step * x_offset;
	mlxdata->min.imag -= move_step * y_offset;
	mlxdata->max.imag -= move_step * y_offset;
}

int mouse_hook(int button, int x, int y, t_mlxdata *mlxdata)
{
    printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
    // Add your mouse event handling logic here
    if (button == 4)
        ft_mouse_zoom_out(mlxdata, x, y, 1.1);
    else if (button == 5)
        ft_mouse_zoom_in(mlxdata, x, y, 1.0 / 1.1);
	else if (button = 7)
		mlxdata->zoom += 0.1;
    mlxdata->draw_function(mlxdata, MAXIMUM_I);
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
    double hue = fmod(angle / (2 * M_PI), 1.0);
    double saturation = 1.0;
    double lightness = 0.5;

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




// #include <math.h>

void calculate_smooth_color_two(double angle, int *r, int *g, int *b, int max_iter)
{
    // Modified color logic with a smoother loop through the entire RGB spectrum
    double t = angle / (4 * M_PI);

    // Use a sinusoidal function for each color component
    *r = (int)(sin(2 * M_PI * t) * 127.5 + 127.5);
    *g = (int)(sin(2 * M_PI * (t + 1.0 / 3.0)) * 127.5 + 127.5);
    *b = (int)(sin(2 * M_PI * (t + 2.0 / 3.0)) * 127.5 + 127.5);
}


// #include <math.h>

// void calculate_smooth_color_two(double angle, int *r, int *g, int *b, int max_iter)
// {
//     // Modified color logic with additional hues for a smoother loop back to the initial color
//     double t = angle / (2 * M_PI);

//     // Use a sinusoidal function to create a smooth loop back
//     double modulation = 0.5 + 0.5 * sin((t + 0.5) * M_PI);

//     // Adjust t with the modulation factor to control the loop frequency
//     t = fmod(t + 0.5 * modulation, 1.0);

//     *r = (int)(9 * (1 - t) * t * t * t * 255);
//     *g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     *b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

//     // Additional hues for a more varied color palette
//     int lila_r = (int)(8.5 * (1 - t) * (1 - t) * t * t * 255);
//     int lila_g = (int)(9 * (1 - t) * t * t * t * 255);
//     int lila_b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);

//     int orange_r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//     int orange_g = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
//     int orange_b = (int)(9 * (1 - t) * t * t * t * 255);

//     // Blend the additional hues with the primary color based on the iteration count
//     double blend_factor = (double)max_iter / 100.0; // Adjust as needed
//     *r = (int)((1 - blend_factor) * *r + blend_factor * lila_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * lila_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * lila_b);

//     // You can add more blending with other hues here based on the iteration count
//     // For example, blend with orange based on the iteration count
//     *r = (int)((1 - blend_factor) * *r + blend_factor * orange_r);
//     *g = (int)((1 - blend_factor) * *g + blend_factor * orange_g);
//     *b = (int)((1 - blend_factor) * *b + blend_factor * orange_b);
// }



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
    // else if (color_logic == 2)
    // {
    //     // Smooth color transition for color logic 2
    //     calculate_smooth_color(angle, &r, &g, &b);
    // }
	else if (color_logic == 2)
        calculate_smooth_color_two(angle, &r, &g, &b, max_iter);
    else
    {
        // Handle unexpected input (optional)
        return 0x000000;
    }

    return (r << 16) | (g << 8) | b;
}



void	ft_default_zoom(t_mlxdata *mlxdata)
{
	mlxdata->zoom = 0.666;
	mlxdata->min.real = -2.0;
	mlxdata->max.real = 2.0;
	mlxdata->min.imag = -1.5;
	mlxdata->max.imag = 1.5;
	mlxdata->center.real = WIDTH / 2;
	mlxdata->center.imag = HEIGHT / 2;
	mlxdata->color_logic = 1;
}

static	ft_default_zoom_j(t_mlxdata *mlxdata)
{
    mlxdata->min.real = -0.845634;
    mlxdata->max.real = 3.154366;
    mlxdata->min.imag = -0.345634;
    mlxdata->max.imag = 2.654366;
    mlxdata->zoom = 0.001808;
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
	if (ft_strncmp(set, "mandelbrot", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = draw_mandelbrot;
		ft_default_zoom(mlxdata);
	}
	else if (ft_strncmp(set, "julia", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = ft_draw_julia;
		ft_default_zoom_j(mlxdata);
	}
}

void ft_draw_julia(t_mlxdata *mlxdata, int max_iter)
{
    int x;
    int y;
    double dx;
    double dy;

    dx = (mlxdata->max.real - mlxdata->min.real) / WIDTH;
    dy = (mlxdata->max.imag - mlxdata->min.imag) / HEIGHT;
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
            ft_process_julia_pixel(mlxdata, x, y, dx, dy, max_iter);
    }
}

void ft_process_julia_pixel(t_mlxdata *mlxdata, int x, int y, double dx, double dy, int max_iter)
{
    t_complex c;
    t_complex z;
    int iter;
    int color;
    int pixel_index;

    // Adjust the calculation of c to take into account the zoom factor
    c.real = mlxdata->min.real + x * dx * mlxdata->zoom;
    c.imag = mlxdata->min.imag + y * dy * mlxdata->zoom;
	z.real = (double)x / WIDTH * 3.0 - 1.5; // Adjust these values as needed
	z.imag = (double)y / HEIGHT * 3.0 - 1.5;

	iter = ft_julia_iteration(c, z, max_iter);
	color = calculate_color(iter, max_iter, mlxdata->color_logic, x, y);
	pixel_index = (y * mlxdata->line_length) + (x * (mlxdata->bits_per_pixel / 8));
	mlxdata->addr[pixel_index] = color >> 16;     // Red
	mlxdata->addr[pixel_index + 1] = color >> 8;  // Green
	mlxdata->addr[pixel_index + 2] = color;       // Blue
}

int	ft_julia_iteration(t_complex c, t_complex z, int max_iter)
{
	int			iter;
	double		real_tmp;
	double		imag_tmp;

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


int main(int argc, char **argv)
{
	t_mlxdata mlxdata;

	if (argc != 2)
	{
		ft_pntf("Usage: ./fractol [mandelbrot/julia]");
		return (1);
	}

	ft_mlx_init(argv[1], &mlxdata);
	mlxdata.draw_function(&mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (0);
}
