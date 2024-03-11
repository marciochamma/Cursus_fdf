/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:26 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/28 12:17:09 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase_pf(size_t n, char *tab, size_t base, char flag)
{
	size_t	count;

	count = 1;
	if (n && flag == '#')
		count += ft_putstr_pf(&tab[16]);
	flag = 0;
	if (n >= base)
		count += ft_putnbrbase_pf(n / base, tab, base, flag);
	write(1, &tab[n % base], 1);
	return (count);
}
