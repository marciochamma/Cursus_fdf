/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:35:28 by mchamma           #+#    #+#             */
/*   Updated: 2023/05/13 16:04:00 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts a given letter to lowercase

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include<stdio.h>
// #include<ctype.h>

// int	main(void)
// {
// 	int	c;

// 	c = 'A';
// 	printf("%c\n",tolower(c));

// 	c = 'A';
// 	printf("%c\n",ft_tolower(c));

// 	return (0);
// }
