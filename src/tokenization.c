/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:05:37 by yelu              #+#    #+#             */
/*   Updated: 2025/05/21 18:05:37 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_type check_token_type(char *basin)
{
	if (basin == NULL)
	{
		ft_putstr_fd("Failed to check user input type", 2);
		exit (1);
	}
	if (ft_strncmp(basin, "|", 2) == 0)
		return (TOKEN_PIPE);
	else if (ft_strncmp(basin, "<", 2) == 0)
		return (TOKEN_REDIRECT_IN);
	else if (ft_strncmp(basin, ">", 2) == 0)
		return (TOKEN_REDIRECT_OUT);
	else if (ft_strncmp(basin, ">>", 3) == 0)
		return (TOKEN_APPEND);
	else if (ft_strncmp(basin, "<<", 3) == 0)
		return (TOKEN_HEREDOC);
	else
		return (TOKEN_WORD);
}

void    init_token(t_data *data, char **basin)
{
    int type;
    int i;
	t_token	*current_word_token;

    i = 0;
	current_word_token = create_word_token(data);
	data->index++;
    while(basin[i])
    {
		type = check_token_type(basin[i]);
		printf("Element's current type: %d\n", type);
		if (type == TOKEN_PIPE)
		{
			current_word_token->basin_buff = data->word.array;
			data->word.array = NULL;
			data->word.word_count = 0;
			create_pipe(data, type);
			data->index++;
			current_word_token = create_word_token(data);
		}
		else if (type == TOKEN_REDIRECT_IN || type == TOKEN_REDIRECT_OUT ||
			type == TOKEN_APPEND || type == TOKEN_HEREDOC)
		{
			i++;
			create_redirects(basin[i], data, type);
			data->index++;
		}
		else
			word_array(data, basin[i]);
		i++;
	}
	current_word_token->basin_buff = data->word.array;
	data->word.array = NULL;
	data->word.word_count = 0;
}
