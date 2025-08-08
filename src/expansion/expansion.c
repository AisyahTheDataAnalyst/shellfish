/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:11:41 by wshee             #+#    #+#             */
/*   Updated: 2025/08/08 20:51:12 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 1. check single/double quote- need to expand or not
// 2. parameter_expansion if got $
// 3. quote_removal
void	expand_tokens(t_token *token, t_exc *exc)
{
	int		i;
	t_token	*curr;
	int		size;

	curr = token;
	size = ft_array_size(token->basin_buff);
	while (curr)
	{
		i = 0;
		while (curr->basin_buff && curr->basin_buff[i])
		{
			check_got_quote(&curr->basin_buff[i], exc);
			i++;
		}
		curr = curr->next;
	}
	curr = token;
	while (curr && curr->basin_buff)
	{
		curr->basin_buff = skip_null_strings(curr->basin_buff, size);
		curr = curr->next;
	}
}

char	**skip_null_strings(char **basin_buff, int size)
{
	char	**new_basin_buff;
	int		i;
	int		j;

	new_basin_buff = malloc(sizeof(char *) * (size + 1));
	if (!new_basin_buff)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (basin_buff[i])
		{
			new_basin_buff[j] = ft_strdup(basin_buff[i]);
			j++;
		}
		i++;
	}
	new_basin_buff[j] = NULL;
	i = 0;
	while (i < size)
		free(basin_buff[i++]);
	free(basin_buff);
	return (new_basin_buff);
}
