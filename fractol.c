/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/03 00:19:03 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*                   B O N U S                                                     .
One more different fractal (more than a hundred different types of fractals are
referenced online).
• The zoom follows the actual mouse position. ✅
• In addition to the zoom: moving the view by pressing the arrows keys. ✅
                                                                                  .
*/

/*                   DONE                                                     .

mouse 4 and 5 zoom in and out ✅
Your program must offer the Julia set and the Mandelbrot set.✅
You must be able to create different Julia sets by passing different parameters to
the program.
A parameter is passed on the command line to define what type of fractal will be
displayed in a window.✅
/*                   T O D O                                                     .

◦ You can handle more parameters to use them as rendering options.
◦ If no parameter is provided, or if the parameter is invalid, the program displays
	a list of available parameters and exits properly.
•solve leaks in memory
• Make the color range shift.
                                                                                  .
*/

// wuki edge of seventeen

int	ft_mlx_init(char *set, t_mlxdata *mlxdata, char **argv, int argc)
{
	ft_error_check(set);
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, set);
	mlxdata->img = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
	mlxdata->addr = mlx_get_data_addr(mlxdata->img, &(mlxdata->bits_per_pixel),
			&(mlxdata->line_length), &(mlxdata->endian));
	if (ft_strncmp(set, "mandelbrot", ft_strlen(set)) == 0)
	{
		mlxdata->draw_function = ft_draw_mandelbrot;
		ft_default_zoom(mlxdata);
	}
	else if (ft_strncmp(set, "julia", ft_strlen(set)) == 0)
	{
		if (argc <= 2)
			ft_julia_error();
		mlxdata->draw_function = ft_draw_julia;
		ft_default_zoom_j(mlxdata, argv);
	}
	else if (ft_strncmp(set, "tricorn", ft_strlen(set)) == 0)
	{
		if (argc <= 2)
			ft_julia_error();
		mlxdata->draw_function = ft_draw_julia;
		ft_default_zoom_j(mlxdata, argv);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	ft_mlx_init(argv[1], &mlxdata, argv, argc);
	mlxdata.draw_function(&mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);

	mlx_loop(mlxdata.mlx);
	// ft_cleanup_all(void);
	return (EXIT_SUCCESS);
}
