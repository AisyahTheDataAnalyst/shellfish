/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:26:36 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 11:37:10 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
// Define the structure of a list node
typedef struct s_list {
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

// Function to get the last node of the list
t_list *ft_lstlast(t_list *lst) {
    if (lst == NULL)
        return NULL;

    while (lst->next)  // Loop until the last node (where lst->next == NULL)
        lst = lst->next;

    return lst;  // Return the last node
}

int main() {
    // Create some sample data for the nodes
    int data1 = 10, data2 = 20, data3 = 30;

    // Create an empty list (head is NULL)
    t_list *head = NULL;

    // Add nodes to the list (adding to the front)
    ft_lstadd_front(&head, ft_lstnew(&data3));  // List: [30]
    ft_lstadd_front(&head, ft_lstnew(&data2));  // List: [20, 30]
    ft_lstadd_front(&head, ft_lstnew(&data1));  // List: [10, 20, 30]

    // Test ft_lstlast to get the last node
    t_list *last = ft_lstlast(head);

    // Print the content of the last node
    if (last != NULL)
        printf("The last node's content is: %d\n", *(int *)last->content);
    else
        printf("The list is empty.\n");

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
