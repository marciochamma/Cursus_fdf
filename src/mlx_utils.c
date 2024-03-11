/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:20:00 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 16:27:09 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put_pixel_to_image(t_app *fdf, int x, int y, int color)
{
	char	*pxl;

	if (fdf->map_x_min < 0)
		x = x + ft_intabs(fdf->map_x_min * fdf->map_scale) + \
		(1000 - ((fdf->map_x_max - fdf->map_x_min) * fdf->map_scale)) / 2;
	else
		x = x + \
		(1000 - ((fdf->map_x_max - fdf->map_x_min) * fdf->map_scale)) / 2;
	if (fdf->map_y_min < 0)
		y = y + ft_intabs(fdf->map_y_min * fdf->map_scale) + \
		(1000 - ((fdf->map_y_max - fdf->map_y_min) * fdf->map_scale)) / 2;
	else
		y = y + \
		(1000 - ((fdf->map_y_max - fdf->map_y_min) * fdf->map_scale)) / 2;
	pxl = fdf->addr + (y * fdf->llength + x * (fdf->bpp / 8));
	*(unsigned int *)pxl = color;
}

int	close_win_key(int keycode, t_app *fdf)
{
	if (keycode == 65307)
	{
		terminate (fdf);
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		exit(0);
	}
	return (0);
}

int	close_win_click(t_app *fdf)
{
	terminate (fdf);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
}
