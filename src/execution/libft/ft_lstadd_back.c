/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:04:15 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/16 16:32:29 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *lst = new  means  when *lst's content is NULL, assigned new's value to *lst
// - must be in this sequence ( A = B, B is assigned to A)
// if we want to recall a previous fn, must just that fn in one line.
// at the 2nd return, means ultimately quit the code right there on. 

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew("Apple");
	t_list	*node2 = ft_lstnew("Ball");
	t_list	*node3 = ft_lstnew("Zebra");

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	
	while (head)
	{
		printf("Last Node: %s\n", (char *)head->content);
		head = head->next;
	}
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/