/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:11:13 by mman              #+#    #+#             */
/*   Updated: 2024/01/04 18:21:00 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*                   T O D O                                   .
- COPY SOMEONES (freeware) RGB LOGIC

- To turn in bonuses to your project, you must include a rule bonus to your
Makefile, which will add all the various headers, librairies or functions that
fr orbidden on the main part of the project. Bonuses must be in a different file
bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus
part evaluation is done separately.

(remove comments, statements, formatting)
// wuki edge of seventeen
*/

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	ft_mlx_init(argv[1], &mlxdata, argv, argc);
	mlxdata.draw_function(&mlxdata, MAXIMUM_I);
	mlx_put_image_to_window(mlxdata.mlx, mlxdata.win, mlxdata.img, 0, 0);
	setup_event_hooks(&mlxdata);
	mlx_loop(mlxdata.mlx);
	ft_cleanup_all(&mlxdata);
	return (EXIT_SUCCESS);
}
