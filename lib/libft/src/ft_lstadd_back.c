/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:30:26 by mchamma           #+#    #+#             */
/*   Updated: 2023/09/27 18:37:27 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the node at the end of the list

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (*lst == NULL)
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next != NULL)
			aux = aux->next;
		aux -> next = new;
	}
}

// #include<stdio.h>

// int	main(void)
// {
// 	int 	content[] = {10, 2, 4, 5};
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*next_node;

// 	lst = NULL;

// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);

// 	new_node = ft_lstnew(&content[1]);
// 	ft_lstadd_back(&lst, new_node);

// 	new_node = ft_lstnew(&content[2]);
// 	ft_lstadd_back(&lst, new_node);

// 	new_node = ft_lstnew(&content[3]);
// 	ft_lstadd_back(&lst, new_node);

// 	while (lst != NULL)
// 	{
// 		printf("%d ", *(int *)lst->content);
// 		next_node = lst -> next;
// 		free(lst);
// 		lst = next_node;
// 	}

// 	return (0);
// }
