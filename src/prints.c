/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:48:05 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/24 15:10:05 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_datasheet(t_app *fdf)
{
	int	angle;

	angle = ANGLE * 180 / 3.14159;
	ft_printf("--- Dimension ---\n");
	ft_printf("W: %d\nH: %d\n", fdf->map_width, fdf->map_height);
	ft_printf("--- Projection ---\n");
	ft_printf("Angle: %d°\n", angle);
	ft_printf("x_max: %d | x_min: %d\n", fdf->map_x_max, fdf->map_x_min);
	ft_printf("y_max: %d | y_min: %d\n", fdf->map_y_max, fdf->map_y_min);
	ft_printf("Scale factor: %dx\n", fdf->map_scale);
	ft_printf("------------------\n");
}
