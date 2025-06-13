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

static void	first_malloc(t_data *data, char *element)
{
	data->word.array = malloc(sizeof(char *) * (2));
	if (!data->word.array)
	{
		// Probably need to free stuff first let's see how
		exit (1);
	}
	data->word.array[0] = ft_strdup(element);
	if (!data->word.array)
	{
		// Free word array allocated and other stuff
		exit (1);
	}
	data->word.array[1] = NULL;
}

static void	ft_realloc(t_data *data, char *element)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc(sizeof(char *) * (data->word.word_count + 2));
	if (!new_array)
	{
		// free stuff before exit
		exit(1); // Need to create function to free arrays, mainly basin (and input?)
	}
	while (i < data->word.word_count)
	{
		new_array[i] = data->word.array[i];
		i++;
	}
	new_array[i] = ft_strdup(element);
	new_array[i + 1] = NULL;
	free_arr(data->word.array);
	data->word.array = new_array;
	// int j = 0; // for testing 
	// while (data->word.array[j])
	// {
	// 	printf("String %s\n", data->word.array[j]);
	// 	j++;
	// }
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
			create_redirects(basin[i + 1], data, type);
			data->index++;
			i++;
		}
		else
		{
			data->word.word_count++;
			if (!data->word.array)
				first_malloc(data, basin[i]);
			else
				ft_realloc(data, basin[i]);
		}
		i++;
	}
}
