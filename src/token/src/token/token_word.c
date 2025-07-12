/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:33:29 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:23:04 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

t_token	*create_word_token(t_input_info *data)
{
	t_token	*new;
	t_token	*current;

	new = malloc(sizeof(t_token));
	if (!new)
		token_free_and_exit(data, "Fatal error - Word token creation failed\n");
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
			current = current->next;
		current->next = new;
	}
	return (new);
}
