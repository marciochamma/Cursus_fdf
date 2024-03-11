/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:39:37 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/27 18:37:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last node of the list

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int 	content[] = {5, 4, 2, 10};
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*next_node;

// 	lst = NULL;

// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[1]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[2]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[3]);
// 	ft_lstadd_front(&lst, new_node);

// 	printf("%p\n", ft_lstlast(lst));

// 	while (lst != NULL)
// 	{
// 		printf("%d ", *(int *)lst->content);
// 		next_node = lst -> next;
// 		free(lst);
// 		lst = next_node;
// 	}

// 	return (0);
// }
