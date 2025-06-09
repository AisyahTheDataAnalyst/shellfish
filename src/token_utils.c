/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:54:16 by yelu              #+#    #+#             */
/*   Updated: 2025/06/04 11:54:16 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    free_arr(char **array)
{
    int i;

    i = 0;
    if (!array)
        return;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

// Only for malloc failed node
void free_token_node(t_token *node)
{
    if (!node) 
        return;
    if (node->basin_buff)
    {
        free(node->basin_buff[0]);
        free(node->basin_buff);
    }
    free(node);
}
