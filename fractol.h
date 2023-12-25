/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:45:12 by mman              #+#    #+#             */
/*   Updated: 2023/12/26 00:39:15 by mman             ###   ########.fr       */
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// Event handling functions
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close_window_event(int keycode, t_vars *vars);

// Utility functions
void	setup_event_hooks(t_vars *vars);
void	draw_pixel(t_vars *vars, int x, int y, int color);
int		close_window(void *param);

// Mandelbrot 
void    ft_do_mandelbrot(t_vars *vars);


#endif
