/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:30:16 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/19 21:18:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//0. declare must on top for normimnette,
//	- newlist : return type && head = NULL
//	- new_node : for assistance to create new map, because != lst
//1. error handling if lst/del/f is null, return NULL
//	- consistency with fn purpose + TRANSFORM linked list
//	- lead to confusion if not handled correctly, dosent act 
//		predictably , instead a map but as a dupliator, NO!
//	- therefore instantly, RETURN NULL!
//2.0 since we are creating new things, start from nothing, both is = NULL
//2. while lst != NULL
// 2.1	create new node applying f on the content
// 2.2	if (new node == NULL): clear that node, since originally return is void
//		must add return NULL since here got t_list * return type
// 2.3	make a full new map: addback with the head = NULL, remember to do &head
// 2.4	make iteraition like i++ : lst = lst->current;
//3. return the head, new_list! 

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !del || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>

static void *ft_shift_one(void *alp)
{
    char *str;
	char *new_str;

	str = (char *)alp;
	new_str = ft_strdup(str); //dup to preserve the original string
    if (new_str) // if its a successful memory allocation
        while (new_str[i])
		{
            new_str[i] = new_str[i] + 1;  
			i++;
		}
    return (void *)new_str;
}

static void del_content(void *content)
{
	free(content);
}

int	main()
{
	t_list	*node1 = ft_lstnew(ft_strdup("AA")); 
	t_list	*node2 = ft_lstnew(ft_strdup("BB"));
	t_list	*node3 = ft_lstnew(ft_strdup("CC"));
	//ft_strdup is needed because we want node own the data
	//instead of just referencing it, so then can alter data
	//with ft_shift_one as needed in ft_lstmap

	if (!node1 || !node2 || !node3)	//Handle memory allocation failure
	{
		printf("Failed to allocate memory for list nodes");
	}
	
	ft_lstadd_back(node1, node2);
	ft_lstadd_back(node1, node3);

	t_list *result = ft_lstmap (node1, ft_shift_one, del_content);

	while (result)
	{
		printf("Replaced Node: %s\n", (char *)result->content);
		result = result->next;
	}
	
	t_list *temp;
	while (node1)
	{
		temp = node1->next;
		free(node1->content);
		free(node1);
		node1 = temp;
	}
	return (0);
}
*/