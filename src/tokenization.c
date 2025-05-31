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

static void	rerealloc(char *element, t_data *data)
{
	char	**new_array;
	int		i;

	i = 0;
	if (!data->word_arr.array)
	{
		data->word_arr.array = malloc(sizeof(char *) * (data->word_arr.word_count + 1));
		if (!data->word_arr.array)
			exit (1);
		data->word_arr.array[0] = NULL;
	}
	new_array = malloc(sizeof(char *) * (data->word_arr.word_count + 2));
	if (!new_array)
		exit(1); // Should I exit and retry instead?
	while (i < data->word_arr.word_count)
	{
		new_array[i] = data->word_arr.array[i];
		i++;
	}
	new_array[i] = ft_strdup(element);
	new_array[i + 1] = NULL;
	free_array(data->word_arr.array);
	data->word_arr.array = new_array;
	int j = 0;
	while (data->word_arr.array[j])
	{
		printf("String %s\n", data->word_arr.array[j]);
		j++;
	}
}

void    init_token(char **basin, t_data *data)
{
    int type;
    int i;

    i = 0;
    while(basin[i])
    {
		pipe_flag = 0;
		type = check_token_type(basin[i]);
		printf("Token type: %d\n", type);
		// while (basin[i] != TOKEN_PIPE)
		if (type == TOKEN_WORD)
		{
			data->word_arr.word_count = 0;
			data->word_arr.word_count++;
			first_malloc(basin[i]);
			i++;
			while (type(basin[i]) == TOKEN_WORD)
				rerealloc(basin[i], data);
				i++;
		}
		if is pipe
			do stuff here

        i++;
    }
	// i = 0;
	// // while (basin[i])
	// // {
		
	// // }
}

