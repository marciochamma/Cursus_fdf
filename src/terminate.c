/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:51:22 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/24 08:07:05 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(t_app *fdf)
{
	int	i;

	i = 0;
	while (fdf->map[i] != 0)
	{
		free (fdf->map[i]);
		i++;
	}
	free(fdf->map);
}

void	error_msg(int e)
{
	ft_printf("Error: ");
	if (e == -1)
		ft_printf("missing FILE\n");
	if (e == -2)
		ft_printf("invalid FILE\n");
	else if (e == -3)
		ft_printf("incomplete MAP\n");
	else if (e == -4)
		ft_printf("MEMORY allocation issue\n");
	else if (e == -5)
		ft_printf("MLX initiation issue\n");
	exit(0);
}
