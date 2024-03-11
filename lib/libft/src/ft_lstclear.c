/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:48:12 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/27 18:37:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every successor of that node, 
// using the function ’del’

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		aux = (*lst)->next;
		(del)((*lst)-> content);
		free (*lst);
		*lst = aux;
	}
}

// void	ft_destroy(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int		*content;
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*nodex;

// 	lst = NULL;

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 10;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 20;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	nodex = new_node;

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 30;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	ft_lstclear(&nodex, ft_destroy);

// 	return (0);
// }
