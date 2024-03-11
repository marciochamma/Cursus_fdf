/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:20:31 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/27 18:37:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Duplicates a string

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// int	main(void)
// {
// 	const char	*str;
// 	char		*ret;

// 	str = "Hello, World!";
// 	ret = strdup(str);
// 	printf("%s\n", ret);
// 	free(ret);

// 	str = "Hello, World!";
// 	ret = ft_strdup(str);
// 	printf("%s\n", ret);
// 	free(ret);

// 	return (0);
// }
