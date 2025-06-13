/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:33:29 by yelu              #+#    #+#             */
/*   Updated: 2025/06/12 21:31:02 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *create_word_token(t_data *data)
{
    t_token *new;
    t_token *current;

    new = malloc(sizeof(t_token));
    if (!new)
    {
        // Free the shits
        exit (1);
    }
    new->basin_buff = NULL;
    new->token_type = TOKEN_WORD;
    new->index = data->index;
    new->next = NULL;
    if (!data->token)
    {
        data->token = new;
        return (new);
    }
    else
    {
        current = data->token;
        while (current->next)
        {
            current = current->next;
            current->next = new;
        }
    }
    return (new);
}

