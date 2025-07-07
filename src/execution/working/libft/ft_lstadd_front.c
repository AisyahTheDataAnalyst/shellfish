/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:26:18 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/19 14:26:34 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return type is void, so no initializing at int main
//no malloc because just replacing existing memory

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int	main()
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew("Apple");
	t_list	*node2 = ft_lstnew("Ball");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2); 

	while (head)//meaning = while head is not NULL
	{
		printf("Node front: %s\n", (char *)head->content);
		head = head->next;
	}
	free(node1);
	free(node2);
	return (0);
}*/