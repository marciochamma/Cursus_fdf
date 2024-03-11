/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:59:08 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/28 12:16:50 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_pf(int n, char flag)
{
	int	unit;
	int	count;

	count = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		unit = (n % 10) * -1 + '0';
		n /= -10;
	}
	else
	{
		if (n >= 0 && (flag == '+' || flag == ' '))
			count += ft_putchar_pf(flag);
		unit = (n % 10) + '0';
		n /= 10;
	}
	flag = 0;
	if (n > 0)
		count += ft_putnbr_pf(n, flag);
	write(1, &unit, 1);
	return (count);
}
