/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2023/12/27 20:47:39 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "fractol_constants.h"
# include "libft/includes/libft.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

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
int		close_window_event(t_vars *vars);
void	setup_event_hooks(t_vars *vars);
int		close_window(t_vars *vars);
void	ft_error(char *str);
void	ft_cleanup_all(t_vars vars);
void	ft_program(t_vars vars);

// Utility functions
void	draw_pixel(t_img *img, int x, int y, int color);

// Mandelbrot 
void    ft_do_mandelbrot(t_vars *vars);
int		mandelbrot_iterations(double real, double imag, int max_iterations);






#endif
