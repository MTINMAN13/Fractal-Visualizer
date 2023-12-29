/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2023/12/30 00:27:19 by mman             ###   ########.fr       */
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
#ifndef M_PI
#define M_PI (3.14159265358979323846264338327950288419716939937510582097494459)
#endif


typedef struct	s_center_axis
{
	double real;
	double imag;
}				t_centr;

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
	int			color_logic;
	t_centr		center;
	t_complex	min;
	t_complex	max;
}				t_mlxdata;

// Event handling functions
int		key_hook(int keycode, t_mlxdata *mlxdata);
int		mouse_hook(int button, int x, int y, t_mlxdata *mlxdata);
int		close_window(t_mlxdata *mlxdata);
int		close_window_event(t_mlxdata *mlxdata);
void	setup_event_hooks(t_mlxdata *mlxdata);
void	ft_error(char *str);

// Utility functions
void	ft_default_zoom(t_mlxdata *mlxdata);
void 	ft_adjust_zoom(t_mlxdata *mlxdata, int x, int y, double zoom_factor);


// Mandelbrot 
// new
int		mandelbrot_iteration(t_complex c, int max_iter);
int 	calculate_color(int iteration, int max_iter, int color_logic, int x, int y);
void	draw_mandelbrot(t_mlxdata *mlxdata, int max_iter);
int		handle_keypress(int keycode, t_mlxdata *mlxdata);

#endif
