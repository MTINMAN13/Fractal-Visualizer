/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2023/12/28 20:02:52 by mman             ###   ########.fr       */
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

# define WIDTH 600
# define HEIGHT 400


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

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_vars;

// Event handling functions
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);
int		close_window_event(t_vars *vars);
void	setup_event_hooks(t_mlxdata *mlxdata);
void	ft_error(char *str);

// Utility functions
void	draw_pixel(t_img *img, int x, int y, int color);

// Mandelbrot 
// new
int		mandelbrot_iteration(t_complex c, int max_iter);
int		calculate_color(int iteration, int max_iter);
void	draw_mandelbrot(t_mlxdata *mlxdata, int max_iter);
int		handle_keypress(int keycode, t_mlxdata *mlxdata);

#endif
