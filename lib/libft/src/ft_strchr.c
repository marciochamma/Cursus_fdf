/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:43:16 by mchamma           #+#    #+#             */
/*   Updated: 2023/10/05 14:14:44 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Searches for the 1st occurrence of the char c in the string str

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&str[i]);
	return (0);
}

// #include<stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	const char	*str;
// 	int			c;

// 	str = "Teste";
// 	c = '\0';

// 	printf("%s\n", strchr(str, c));
// 	printf("%s\n", ft_strchr(str, c));

// 	return (0);
// }
