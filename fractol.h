/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:39:42 by mman              #+#    #+#             */
/*   Updated: 2023/11/26 06:40:19 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux-master/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define MALLOC_ERROR	1
# define ERROR_MESSAGE	"Hjustne mame problem"
# define WIDTH			800
# define HEIGHT			400

 * COLORS
*/
# define BLACK			0x000000  // RGB(0, 0, 0)
# define WHITE			0xFFFFFF  // RGB(255, 255, 255)
# define RED  			0xFF0000  // RGB(255, 0, 0)
# define GREEN			0x00FF00  // RGB(0, 255, 0)
# define BLUE 			0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST		0xFF00FF  // A vibrant magenta
# define LIME_SHOCK			0xCCFF00  // A blinding lime
# define NEON_ORANGE		0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE	0x660066  // A deep purple
# define AQUA_DREAM			0x33CCCC  // A bright turquoise
# define HOT_PINK			0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE		0x0066FF  // A radiant blu
# define LAVA_RED			0xFF3300  // A bright, molten r	ed

typedef struct	s_complex
{
	double	x;
	double	y;
}					t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}					t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shitf_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}					t_fractal;

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_mlx_data;

#endif
