/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:51:42 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 14:53:34 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_app	fdf;

	if (argc != 2)
		error_msg(-1);
	if (map_load(&fdf, argv[1]) < 0)
		error_msg (map_load(&fdf, argv[1]));
	print_datasheet(&fdf);
	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
		error_msg (-5);
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, "Wireframe Model");
	fdf.img = mlx_new_image(fdf.mlx, 1000, 1000);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.llength, &fdf.endian);
	map_draw(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_hook(fdf.win, 17, 0, close_win_click, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, close_win_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
