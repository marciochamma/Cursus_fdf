/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:01:30 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 14:14:56 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intcmp(int a, int b, char c)
{
	if (c == '+')
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (c == '-')
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	return (0);
}
