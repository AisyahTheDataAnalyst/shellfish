/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:24:02 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/20 15:32:39 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_lstnew only malloc for creating linkedlist
// ft_strdup in ft_lstnew to malloc for string into the linked list
// conclusion, in linked list, need to malloc for string within the malloc of 
//  	linked list itself

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

static void	ft_add(void *alp)
{
	((char *)alp)[0] = 'X';
}

int	main()
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew(ft_strdup("AA"));
	t_list	*node2 = ft_lstnew(ft_strdup("BB"));
	t_list	*node3 = ft_lstnew(ft_strdup("CC"));

	if (!node1 || !node2 || !node3)
	{
		// Handle memory allocation failure
		perror("Failed to allocate memory for list nodes");
		return 1;
	}

	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	t_list	*cap = head;

	ft_lstiter(cap, ft_add);

	while (cap)
	{
		printf("Modified Node: %s\n", (char *)cap->content);
		cap = cap->next;
	}
	
	t_list *temp;
	while (head)
	{
		temp = head->next;
		free(head->content);
		free(head);
		head = temp;
	}
	return (0);
}
*/