/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:09:00 by yelu              #+#    #+#             */
/*   Updated: 2025/07/30 20:12:53 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"
#include "../include/ast.h"
#include "../include/minishell.h"

int	init_tokens(t_data *data, t_input_info *b_token, char *input, t_exc *exc)
{
	if (!input)
		exit(1);
	init_data(b_token, data);
	b_token->input = ft_strdup(input);
	if (b_token->input)
		free(input);
	if (!quote_check(b_token, exc))
		return (free(b_token->input), 0);
	if (!normalize_input(b_token, exc))
		return (free(b_token->input), 0);
	b_token->split_array = ft_split(b_token->input, ' ');
	if (!b_token->split_array)
		return (free(b_token->input), 0);
	free(b_token->input);
	replace_space(b_token->split_array);
	if (!check_input(b_token->split_array, exc))
		return (free_arr(b_token->split_array), 0);
	create_token(b_token);
	if (!b_token->token)
		return (0);
	free_arr(b_token->split_array);
	data->token = b_token->token;
	return (1);
}

void	free_token_list(t_data *data)
{
	t_token	*temp;
	int		i;

	while (data->token)
	{
		temp = data->token->next;
		if (data->token->basin_buff)
		{
			i = 0;
			while (data->token->basin_buff[i])
			{
				free(data->token->basin_buff[i]);
				i++;
			}
			free(data->token->basin_buff);
		}
		free(data->token);
		data->token = temp;
	}
	data->token = NULL;
}

void	quote_copy(char *input, char *cleaned, int *i, int *j)
{
	if (input[*i] == '"')
	{
		cleaned[(*j)++] = input[(*i)++];
		while (input[*i] != '"' && input[*i])
			cleaned[(*j)++] = input[(*i)++];
	}
	else if (input[*i] == '\'')
	{
		cleaned[(*j)++] = input[(*i)++];
		while (input[*i] != '\'' && input[*i])
			cleaned[(*j)++] = input[(*i)++];
	}
}
