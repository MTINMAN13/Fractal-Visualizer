/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2023/12/29 11:44:05 by mman             ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 800


typedef struct	s_center_axis
{
	double x;
	double y;
}				t_center_axis;

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

// Event handling functions
int		key_hook(int keycode, t_mlxdata *mlxdata);
int		mouse_hook(int button, int x, int y, t_mlxdata *mlxdata);
int		close_window(t_mlxdata *mlxdata);
int		close_window_event(t_mlxdata *mlxdata);
void	setup_event_hooks(t_mlxdata *mlxdata);
void	ft_error(char *str);

// Utility functions


// Mandelbrot 
// new
int		mandelbrot_iteration(t_complex c, int max_iter);
int		calculate_color(int iteration, int max_iter);
void	draw_mandelbrot(t_mlxdata *mlxdata, int max_iter);
int		handle_keypress(int keycode, t_mlxdata *mlxdata);

#endif
