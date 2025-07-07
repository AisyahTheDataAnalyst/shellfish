/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:49:33 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 15:07:32 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	count = 0;
	if (lst == NULL)
		return (count);
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
/**
 * typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

// Function to create a new node
t_list *ft_lstnew(void *content) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the front of the list
void ft_lstadd_front(t_list **alst, t_list *new) {
    new->next = *alst;
    *alst = new;
}

// Function to count the number of nodes in the list
int ft_lstsize(t_list *lst) {
    t_list *tmp = lst;
    int count = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        count++;
    }

    return count;
}

int main() {
    // Create some sample data for the nodes
    int data1 = 10, data2 = 20, data3 = 30;

    // Create an empty list (head is NULL)
    t_list *head = NULL;

    // Add nodes to the list
    ft_lstadd_front(&head, ft_lstnew(&data3));  // List: [30]
    ft_lstadd_front(&head, ft_lstnew(&data2));  // List: [20, 30]
    ft_lstadd_front(&head, ft_lstnew(&data1));  // List: [10, 20, 30]

    // Test ft_lstsize to count the number of nodes
    int size = ft_lstsize(head);
    
    // Print the result
    printf("The list contains %d node(s).\n", size);

    // Free the allocated memory (important for memory management)
    t_list *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
} 
**/
