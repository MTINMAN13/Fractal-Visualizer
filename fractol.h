/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2024/01/04 19:47:20 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 800
# ifndef M_PI
#  define M_PI 3.141592653589793238462643383279502884197169399375105820974944
# endif

# ifndef MAXIMUM_I
#  define MAXIMUM_I 100
# endif

typedef struct s_center_axis
{
	double	real;
	double	imag;
}				t_centr;

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_mlxdata
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	int			color_logic;
	int			c_offset;
	t_centr		center;
	t_complex	min;
	t_complex	max;
	t_complex	julia;
	void		(*draw_function)(struct s_mlxdata *, int); // Function pointer
}				t_mlxdata;

// Event handling functions
int		ft_key_hook(int keycode, t_mlxdata *mlxdata);
int		ft_mouse_hook(int button, int x, int y, t_mlxdata *mlxdata);
int		close_window(t_mlxdata *mlxdata);
int		ft_close_window_event(t_mlxdata *mlxdata);
void	setup_event_hooks(t_mlxdata *mlxdata);
// error
void	ft_error(char *str);
void	ft_error_check(char *set);
void	ft_julia_error(void);

// keymapping func.
void	ft_adjust_render(t_mlxdata *mlxdata, char dir_sign, char real_imag_sign, double move_step);
void	ft_zoom_in(t_mlxdata *mlxdata, int x, int y, double zoom_factor);
void	ft_zoom_out(t_mlxdata *mlxdata, int x, int y, double zoom_factor);
void	ft_process_movement(int keycode, t_mlxdata *mlxdata, double move_step);
void	ft_process_other_keys(int keycode, t_mlxdata *mlxdata);


// Utility functions
// tools
void	ft_default_zoom(t_mlxdata *mlxdata);
void	ft_default_zoom_j(t_mlxdata *mlxdata, double real, double imag);
void	ft_default_zoom_mtri(t_mlxdata *mlxdata);
double	ft_influence(t_mlxdata *mlxdata);

// col
void	ft_color_switch(t_mlxdata *mlxdata);
void	ft_process_color_shift(int keycode, t_mlxdata *mlxdata);
void	ft_shift_left(t_mlxdata *mlxdata);
void	ft_shift_right(t_mlxdata *mlxdata);

// utils - RUNTIME
void	ft_cleanup_all(t_mlxdata *mlxdata);
void	ft_switch(char *set, t_mlxdata *mlxdata, char **argv, int argc);
int		ft_mlx_init(char *set, t_mlxdata *mlxdata, char **argv, int argc);


// Mandelbrot
// new
int		ft_mandelbrot_iteration(t_complex c, int max_iter);
int		ft_calculate_color(int iteration, int max_iter,
			t_mlxdata *mlxdata, int x, int y);
void	ft_draw_mandelbrot(t_mlxdata *mlxdata, int max_iter);
int		handle_keypress(int keycode, t_mlxdata *mlxdata);


// Julia
// new
void	ft_process_julia_pixel(t_mlxdata *mlxdata, int x, int y, double dx, double dy, int max_iter);
int		ft_julia_iteration(t_complex c, t_complex z, int max_iter);
void	ft_draw_julia(t_mlxdata *mlxdata, int max_iter);
int		ft_process_julia_patterns(int keycode, t_mlxdata *mlxdata);


// Tri
//new
void	ft_draw_mandelbar(t_mlxdata *mlxdata, int max_iter);
void 	ft_draw_burning_ship(t_mlxdata *mlxdata, int max_iter);


#endif
