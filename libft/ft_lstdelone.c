/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:46:17 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/19 15:59:08 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1st return means this is a mistake just return nothing
// this fn just deletes 1 node, 
// - doesnt handle next ptr,
// - need to rewiring properly the list and duty to the caller

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>

static void del_content(void *content)
{
	free(content);
}

int	main()
{
	t_list *root = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("11"));
	t_list *node2 = ft_lstnew(ft_strdup("22"));
	t_list *node3 = ft_lstnew(ft_strdup("33"));

	ft_lstadd_front(&root, node3);
	ft_lstadd_front(&root, node2);
	ft_lstadd_front(&root, node1);

	if (node1->next == node2)
		node1->next = node2->next;
	
	ft_lstdelone(node2, del_content);

	t_list	*result = root;

	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
	return (0);
}*/
