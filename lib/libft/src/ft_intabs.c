/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:56:34 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/21 14:01:22 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intabs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}
