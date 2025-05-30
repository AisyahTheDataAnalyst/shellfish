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

static t_type check_token_type(char *basin)
{
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

static void	token_word(char *element, t_word_arr *temp_arr)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc(sizeof(char *) * (temp_arr->word_count + 2));
	if (!new_array)
		exit(1); // Should I exit and retry instead?
	while (i < temp_arr->word_count)
	{
		new_array[i] = temp_arr->array[i];
		i++;
	}
	new_array[i] = ft_strdup(element);
	new_array[i + 1] = NULL;
	free(temp_arr->array);
	temp_arr->array = new_array;
	temp_arr->word_count += 1;
}

void    init_token(char **basin, t_word_arr *temp_arr)
{
    int type;
    int i;

    i = 0;
    while(basin[i])
    {
        type = check_token_type(basin[i]);
		if (type == TOKEN_WORD)
		{
			temp_arr->word_count++;
			printf("How many elements: %d", temp_arr->word_count);
			token_word(basin[i], temp_arr)
		}
        i++;
    }
}
