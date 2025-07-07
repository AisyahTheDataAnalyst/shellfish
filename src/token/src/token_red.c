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

// Create all redirection nodes and append at the end
t_token *create_redirects(char *s1, t_data *data, int type)
{
	t_token *new;
	t_token *current;

	new = malloc(sizeof(t_token));
	if (!new)
	{
		// Free some shit
		exit (1);
	}
	new->basin_buff = malloc(sizeof(char *) * 2);
	if (!new->basin_buff)
	{
		// Free some shit
		exit (1);
	}
	new->basin_buff[0] = ft_strdup(s1);
	if (!new->basin_buff[0])
	{
		// Free some shit
		exit (1);
	}
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
	{
		current = data->token;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}
