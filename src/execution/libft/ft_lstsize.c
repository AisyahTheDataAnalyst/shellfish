/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:57:10 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/18 20:24:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// must use a temporary t_list *ptr to preserve the original 1st pointer
// in the context of linked list, while (ptr) also means while ptr is not NULL
// no need of error handling on ptr coz n is 0 already from the start

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*ptr;

	n = 0;
	ptr = lst;
	while (ptr)
	{
		n++;
		ptr = ptr->next;
	}
	return (n);
}
/*
#include <stdio.h>

int	main()
{
	t_list *tail = NULL;
	t_list *node1 = ft_lstnew("Hello1");
	t_list *node2 = ft_lstnew("Hello2");
	t_list *node3 = ft_lstnew("Hello3");

	ft_lstadd_front(&tail, node1);
	ft_lstadd_front(&tail, node2);
	ft_lstadd_front(&tail, node3);
	t_list *chain = tail;

	int result = ft_lstsize(chain);

	if (chain)
		printf("Total nodes: %d\n", result);
	return (0);
}*/
