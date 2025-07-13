/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:00:12 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/19 13:57:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sizeof = returns a size_t as in [void *malloc(size_t size)], using %zu
//  - good for portability in 32/64system && memory allocation
// since we're creating a new node, typically starts as a standalone node 
//  - in the list, thus next = NULL
// initializing next=NULL so no garbage values interfere with the program logic
// Assigns the content passed to the function into the content field 
// - of the newly created node
// t_list = %p = (nil) - also null, just a matter of formatting choice by C's 4
// - standard library implementation
// need to cast (t_list *)malloc because its not copmpatible with void *
// char * is compatible with void * so no need to cast on malloc
// in int main = (void *)content. int => *(int *) , char => *(char *), 
// - char * / void * => (char *)/(void *)
// If (!content)
// 	return NULL
// 	- cannot do this because we are doing a new one anyways, of course its
// 	- going to be null at first
// int main = put ft_strdup so that 
// 		nodes in ft_lstnew own the data, not just stores pointer
// 		- all this time, content and next are just stored pointers to data
//		- pointer = its just referencing the data

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>

int	main()
{
	int value = 42;
	t_list *newnode = ft_lstnew(&value);

	if (newnode)
	{
		printf("Node content: %d\n", *(int *)(newnode->content));
		printf("Node next: %p\n", (void *)newnode->next);
	}

	free(newnode);
	return (0);
}
*/