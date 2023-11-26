/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:39:42 by mman              #+#    #+#             */
/*   Updated: 2023/11/26 05:33:12 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux-master/mlx.h"
# include <stdlib.h>
# include <math.h>

# define MALLOC_ERROR	1
# define ERROR_MESSAGE	"Hjustne mame problem"
# define WIDTH			400
# define HEIGHT			400

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
// https://youtu.be/ANLW1zYbLcs?si=mkkf9zd84ZGVmxFU&t=2837
};

typedef struct	s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_mlx_data;

#endif
