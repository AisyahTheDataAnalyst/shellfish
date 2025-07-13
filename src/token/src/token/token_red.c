/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_red_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:06:42 by yelu              #+#    #+#             */
/*   Updated: 2025/06/02 18:06:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

static t_token	*loop_and_append(t_input_info *data, t_token *new)
{
	t_token	*current;

	current = data->token;
	while (current->next)
		current = current->next;
	current->next = new;
	return (new);
}

// Create all redirection nodes and append at the end
t_token	*create_redirects(char *s1, t_input_info *data, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		token_free_and_exit(data, "Fatal error - Redirection token failed\n");
	new->basin_buff = malloc(sizeof(char *) * 2);
	if (!new->basin_buff)
		token_free_and_exit(data, "Fatal error - Redirection token failed\n");
	new->basin_buff[0] = ft_strdup(s1);
	if (!new->basin_buff[0])
		token_free_and_exit(data, "Fatal error - Word token creation failed\n");
	new->basin_buff[1] = NULL;
	new->token_type = type;
	new->index = data->index;
	new->next = NULL;
	if (!data->token)
	{
		data->token = new;
		return (new);
	}
	else
		new = loop_and_append(data, new);
	return (new);
}
