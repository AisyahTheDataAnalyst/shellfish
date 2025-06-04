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

// static t_type check_token_type(char *basin)
// {
// 	if (basin == NULL)
// 	{
// 		printf("Failed to check user input type");
// 		exit (1);
// 	}
// 	if (ft_strncmp(basin, "|", 2) == 0)
// 		return (TOKEN_PIPE);
// 	else if (ft_strncmp(basin, "<", 2) == 0)
// 		return (TOKEN_REDIRECT_IN);
// 	else if (ft_strncmp(basin, ">", 2) == 0)
// 		return (TOKEN_REDIRECT_OUT);
// 	else if (ft_strncmp(basin, ">>", 3) == 0)
// 		return (TOKEN_APPEND);
// 	else if (ft_strncmp(basin, "<<", 3) == 0)
// 		return (TOKEN_HEREDOC);
// 	else
// 		return (TOKEN_WORD);
// }

// static void	ft_realloc(char *element, t_data *data)
// {
// 	char	**new_array;
// 	int		i;

// 	i = 0;
// 	if (!data->word_arr.array)
// 	{
// 		data->word_arr.array = malloc(sizeof(char *) * (data->word_arr.word_count + 1));
// 		if (!data->word_arr.array)
// 			exit (1);
// 		data->word_arr.array[0] = NULL;
// 	}
// 	new_array = malloc(sizeof(char *) * (data->word_arr.word_count + 2));
// 	if (!new_array)
// 		exit(1); // Should I exit and retry instead?
// 	while (i < data->word_arr.word_count)
// 	{
// 		new_array[i] = data->word_arr.array[i];
// 		i++;
// 	}
// 	new_array[i] = ft_strdup(element);
// 	new_array[i + 1] = NULL;
// 	free_array(data->word_arr.array);
// 	data->word_arr.array = new_array;
// 	int j = 0;
// 	while (data->word_arr.array[j])
// 	{
// 		printf("String %s\n", data->word_arr.array[j]);
// 		j++;
// 	}
// }

// void    init_token(char **basin, t_data *data)
// {
//     int type;
//     int i;

//     i = 0;
//     while(basin[i])
//     {
// 		type = check_token_type(basin[i]);
// 		printf("What is type now: %d\n", type);
// 		while (basin[i] && type != TOKEN_PIPE)
// 		if (type == TOKEN_PIPE)
// 		{
// 			create_pipe(data, type);
// 			data->index++;
// 		}
// 		else if (type == TOKEN_REDIRECT_IN)
// 		{
// 			create_redirect_in(basin[i], basin[i + 1], data, type);
// 			data->index++;
// 			i++;
// 		}
// 		else if (type == TOKEN_REDIRECT_OUT)
// 		{
// 			create_redirect_out(basin[i], basin[i + 1], data, type);
// 			data->index++;
// 			i++;
// 		}
// 		else if (type == TOKEN_APPEND)
// 		{
// 			create_append(basin[i], basin[i + 1], data, type);
// 			data->index++;
// 			i++;
// 		}
// 		else if (type == TOKEN_HEREDOC)
// 		{
// 			create_heredoc(basin[i], basin[i + 1], data, type);
// 			data->index++;
// 			i++;
// 		}
// 		else
// 		{
// 			data->word_arr.word_count = 0;
// 			data->word_arr.word_count++;
// 			first_malloc(basin[i]);
// 			i++;
// 			while (type(basin[i]) == TOKEN_WORD)
// 				rerealloc(basin[i], data);
// 				i++;
// 		}
//     	i++;
//     }
// }

char	*normalize_input(char *input)
{
	int	i;
	char *cleaned_input;
	int	len;
	int j;

	len = ft_strlen(input);
	cleaned_input = malloc(len * 2 + 1);
	if (!cleaned_input)
	{
		perror("Input allocation failed");
		exit (1);
	}
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '>' || input[i] == '<' || input[i] == '|' || input[i] == '&')
		{
			if ((input[i] == '>' || input[i] == '<' || input[i] == '|' || 
				input[i] == '&') && (input[i] == input[i + 1]))
			{
				cleaned_input[j++] = ' ';
				cleaned_input[j++] = input[i++];
				cleaned_input[j++] = input[i++];
				cleaned_input[j++] = ' ';
			}
			else 
			{
				cleaned_input[j++] = ' ';
				cleaned_input[j++] = input[i++];
				cleaned_input[j++] = ' ';
			}
		}
		else
			cleaned_input[j++] = input[i++];
	}
	cleaned_input[j] = '\0';
	free(input);
	return (cleaned_input);
}
