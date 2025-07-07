/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:11:18 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/19 14:09:36 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if (lst->next)  means  checks if next pointer is NOT NULL 
// if (!lst->next)  OR  if (lst->next == NULL)
//  - means  if next pointer of current lst is NULL 

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

int	main()
{
	t_list	*node1 = ft_lstnew("Hi");
	t_list	*node2 = ft_lstnew("Hello");
	t_list	*node3 = ft_lstnew("Ni Hao");
	t_list	*node4 = ft_lstnew("Annyeong");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	t_list *lastnode = ft_lstlast(node1);

	if(lastnode)
	{
		printf("Node1: %s\n", (char *)node1-> content);
		printf("Node2: %s\n", (char *)node2-> content);
		printf("Node3: %s\n", (char *)node3-> content);
		printf("Node4: %s\n", (char *)node4-> content);
		printf("Oldest Node: %s\n", (char *)lastnode-> content);
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}*/