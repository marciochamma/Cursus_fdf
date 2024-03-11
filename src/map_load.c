/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:09 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 17:08:12 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_data_compl(t_app *fdf, int fd)
{
	char	**aux;
	char	*line;
	int		h;
	int		w;

	line = get_next_line(fd);
	h = 0;
	while (h < fdf->map_height)
	{
		aux = ft_split (line, ' ');
		w = 0;
		while (w < fdf->map_width)
		{
			fdf->map[h][w].x = w;
			fdf->map[h][w].y = h;
			fdf->map[h][w].z = ft_atoi(aux[w]);
			fdf->map[h][w].color = ft_atoi_hexa(fx_strchr(aux[w], ','));
			free(aux[w]);
			w++;
		}
		free(aux);
		free(line);
		line = get_next_line(fd);
		h++;
	}
}

void	add_data(t_app *fdf, char *path)
{
	int		fd;

	fd = open (path, O_RDONLY);
	add_data_compl(fdf, fd);
	close(fd);
}

int	map_load(t_app *fdf, char *path)
{
	int	h;

	if (map_dim(fdf, path) < 0)
		return (map_dim(fdf, path));
	fdf->map = ft_calloc((fdf->map_height + 1), sizeof(t_point *));
	if (!fdf->map)
		return (-4);
	h = 0;
	while (h < fdf->map_height)
	{
		fdf->map[h] = ft_calloc((fdf->map_width + 1), sizeof(t_point));
		if (!fdf->map[h])
			return (-4);
		h++;
	}
	fdf->map[h] = NULL;
	add_data(fdf, path);
	map_proj_dim(fdf);
	return (0);
}
