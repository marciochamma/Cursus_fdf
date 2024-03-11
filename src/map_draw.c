/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:27:22 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 17:07:30 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	bresenham_compl(t_point *a, t_point *b)
{
	if (ft_intabs(b->x - a->x) > ft_intabs(b->y - a->y))
		return (ft_intabs(b->x - a->x) / 2);
	else
		return (-ft_intabs(b->y - a->y) / 2);
}

void	bresenham(t_app *fdf, t_point *a, t_point *b)
{
	int	err;
	int	err2;
	int	x;
	int	y;

	x = a->x;
	y = a->y;
	err = bresenham_compl(a, b);
	while (1)
	{
		mlx_put_pixel_to_image(fdf, x, y, a->color);
		if (x == b->x && y == b->y)
			break ;
		err2 = err;
		if (err2 > -ft_intabs(b->x - a->x))
		{
			err -= ft_intabs(b->y - a->y);
			x += ft_intsign(b->x - a->x);
		}
		if (err2 < ft_intabs(b->y - a->y))
		{
			err += ft_intabs(b->x - a->x);
			y += ft_intsign(b->y - a->y);
		}
	}
}

void	isometric(t_app *fdf, t_point *iso, int h, int w)
{
	int		f;

	f = fdf->map_scale;
	iso->x = ((fdf->map[h][w].x - fdf->map[h][w].y) * cos(ANGLE)) * f;
	iso->y = ((fdf->map[h][w].x + fdf->map[h][w].y) * sin(ANGLE) \
		- (fdf->map[h][w].z * 0.1)) * f;
	iso->color = fdf->map[h][w].color;
}

void	add_line(t_app *fdf, int h, int w)
{
	t_point	*a;
	t_point	*b;

	a = malloc(sizeof(t_point));
	b = malloc(sizeof(t_point));
	if (fdf->map[h][w].x < fdf->map_width - 1)
	{
		isometric(fdf, a, h, w);
		isometric(fdf, b, h, w + 1);
		bresenham(fdf, a, b);
	}
	if (fdf->map[h][w].y < fdf->map_height - 1)
	{
		isometric(fdf, a, h, w);
		isometric(fdf, b, h + 1, w);
		bresenham(fdf, a, b);
	}
	free (a);
	free (b);
}

void	map_draw(t_app *fdf)
{
	int	h;
	int	w;

	h = 0;
	while (h < fdf->map_height)
	{
		w = 0;
		while (w < fdf->map_width)
		{
			add_line(fdf, h, w);
			w += 1;
		}
		h += 1;
	}
}
