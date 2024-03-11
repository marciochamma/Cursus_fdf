/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:43:10 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/22 12:39:52 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"

# define ANGLE	0.7853981634
# define FACTOR	1.5

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int		bpp;
	int		llength;
	int		endian;
	t_point		**map;
	int		map_width;
	int		map_height;
	int		map_x_max;
	int		map_y_max;
	int		map_x_min;
	int		map_y_min;
	int		map_scale;
}	t_app;

int	map_load(t_app *fdf, char *path);

void	map_draw(t_app *fdf);

int	map_dim(t_app *fdf, char *path);

int	map_proj_dim(t_app *fdf);

void	print_datasheet(t_app *fdf);

char	*fx_strchr(const char *str, int c);

void	mlx_put_pixel_to_image(t_app *data, int x, int y, int color);

int	close_win_key(int keycode, t_app *var);

int	close_win_click(t_app *var);

void	terminate(t_app *fdf);

void	error_msg(int e);

#endif
