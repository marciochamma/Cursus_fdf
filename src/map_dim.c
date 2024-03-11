/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:30:17 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 15:20:02 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_dim(t_app *fdf, char *path)
{
	char	*line;
	int		fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		return (-2);
	line = get_next_line(fd);
	fdf->map_height = 0;
	fdf->map_width = 0;
	while (line)
	{
		fdf->map_width += ft_count_words(line, ' ');
		free(line);
		line = get_next_line(fd);
		fdf->map_height++;
	}
	close(fd);
	if (fdf->map_width % fdf->map_height > 0)
		return (-3);
	fdf->map_width /= fdf->map_height;
	return (0);
}

void	map_proj_dim_compl(t_app *fdf)
{
	int	w;
	int	h;
	int	x;
	int	y;

	h = 0;
	while (h < fdf->map_height)
	{
		w = 0;
		while (w < fdf->map_width)
		{
			x = (fdf->map[h][w].x - fdf->map[h][w].y) * cos(ANGLE);
			y = (fdf->map[h][w].x + fdf->map[h][w].y) * sin(ANGLE) \
				- (fdf->map[h][w].z * 0.1);
			fdf->map_x_max = ft_intcmp(fdf->map_x_max, x, '+');
			fdf->map_x_min = ft_intcmp(fdf->map_x_min, x, '-');
			fdf->map_y_max = ft_intcmp(fdf->map_y_max, y, '+');
			fdf->map_y_min = ft_intcmp(fdf->map_y_min, y, '-');
			w += 1;
		}
		h += 1;
	}
}

int	map_proj_dim(t_app *fdf)
{
	fdf->map_x_max = 0;
	fdf->map_x_min = 0;
	fdf->map_y_max = 0;
	fdf->map_y_min = 0;
	map_proj_dim_compl(fdf);
	fdf->map_scale = (1000 / ft_intcmp (fdf->map_x_max - fdf->map_x_min, \
		fdf->map_y_max - fdf->map_y_min, '+')) / FACTOR;
	if (fdf->map_scale < 1)
		fdf->map_scale = 1;
	return (0);
}
