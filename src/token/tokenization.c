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

#include "../include/token.h"
#include "../include/minishell.h"
#include "../libft/libft.h"

static void	pipe_creation(t_input_info *b_token, t_token **current, int type)
{
	(*current)->basin_buff = b_token->word.array;
	b_token->word.array = NULL;
	b_token->word.count = 0;
	create_pipe(b_token, type);
	b_token->index++;
	(*current) = create_word_token(b_token);
	b_token->index++;
}

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

void	create_token(t_input_info *b_token)
{
	int	type;
	int	i;
	t_token	*current_word_token;

	i = 0;
	current_word_token = create_word_token(b_token);
	b_token->index++;
	while(b_token->split_array[i])
	{
		type = check_token_type(b_token->split_array[i]);
		if (type == TOKEN_PIPE)
			pipe_creation(b_token, &current_word_token, type);
		else if (type >= TOKEN_HEREDOC && type <= TOKEN_REDIRECT_OUT)
		{
			i++;
			create_redirects(b_token->split_array[i], b_token, type);
			b_token->index++;
		}
		else
			word_array(b_token, b_token->split_array[i]);
		i++;
	}
	current_word_token->basin_buff = b_token->word.array;
	b_token->word.array = NULL;
	b_token->word.count = 0;
}
