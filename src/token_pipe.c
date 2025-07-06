/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:04:24 by yelu              #+#    #+#             */
/*   Updated: 2025/06/02 15:04:24 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Create pipe node and append node at the end
t_token	*create_pipe(t_data *data, int type)
{
	t_token	*new;
	t_token	*current;

	new = malloc(sizeof(t_token));
	if (!new)
		token_free_and_exit(data, "Pipe creation malloc failed\n");
	new->basin_buff = NULL;
	new->token_type = type;
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
