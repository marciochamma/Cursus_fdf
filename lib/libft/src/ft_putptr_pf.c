/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:04:41 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/28 12:20:41 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_pf(size_t address)
{
	int	count;

	count = 1;
	if (!address)
		return (ft_putstr_pf("(nil)"));
	if (address < 16)
	{
		ft_putstr_pf(&LOWER[16]);
		count += 2;
	}
	else
		count += ft_putptr_pf(address / 16);
	write(1, &LOWER[address % 16], 1);
	return (count);
}
