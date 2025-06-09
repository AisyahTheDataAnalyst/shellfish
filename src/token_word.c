/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:33:29 by yelu              #+#    #+#             */
/*   Updated: 2025/06/09 22:52:50 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token *first_word_token(t_data *data)
{
    t_token *new;

    new = malloc(sizeof(t_token));
    if (!new)
    {
        // Free the shits
        exit (1);
    }
    new->basin_buff = NULL;
    new->token_type = TOKEN_WORD;
    new->index = 0;
    new->next = NULL;
    data->token = new;
    return (new);
}

t_token *loop_word_token(t_data *data)
{
    
}