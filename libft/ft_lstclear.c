/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:47:38 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/20 14:41:20 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ** = pointing to the pointer, *lst thats pointing to the first node, lst
// ** bcoz want to change the value of the *lst
// 1. assign pointer next to temp, then temp assign back to the *lst
// 		- 	the temp is the temporary HEAD
// temp is to store pointer to the next node while deleting them one by one 
// free is in the ft_delone

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
/*
#include <stdio.h>


static void	del_content(void *content)
{
	free(content);
}

int     main()
{
	t_list *root = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("11"));
	t_list *node2 = ft_lstnew(ft_strdup("22"));
	t_list *node3 = ft_lstnew(ft_strdup("33"));
					        
	ft_lstadd_front(&root, node3);
	ft_lstadd_front(&root, node2);
	ft_lstadd_front(&root, node1);
	t_list  *result = root;
	int n = 0;

	printf("Linked list:\n");	
	while (result)
	{
		printf("Node %d: %s\n", n+1, (char *)result->content);
		result = result->next;
		n++;
	}

	ft_lstclear(&result, del_content);
	if (!result)
		printf("Cleared linked list.\n");
	else
		printf("Linkedlist still exist\n");
	return (0);
}
*/