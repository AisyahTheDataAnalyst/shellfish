/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:48:57 by yelu              #+#    #+#             */
/*   Updated: 2024/11/16 11:24:46 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/**
int main(void)
{
	char *content = "Hello world!";
	t_list *new_elem = ft_lstnew(content);

	if (new_elem != NULL)
	{
		printf("Content: %s\n", new_elem->content);
	}
	free(new_elem);
	return 0;
}
**/