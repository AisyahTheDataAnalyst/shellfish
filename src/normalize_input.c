/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:02:26 by yelu              #+#    #+#             */
/*   Updated: 2025/07/04 16:46:52 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*normalizing_check(char *input, char *cleaned)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			cleaned[j++] = input[i++];
			while (input[i] != '"' && input[i])
				cleaned[j++] = input[i++];
		}
		else if (input[i] == '\'')
		{
			cleaned[j++] = input[i++];
			while (input[i] != '\'' && input[i])
				cleaned[j++] = input[i++];
		}
		else if (input[i] == '>' || input[i] == '<' || input[i] == '|')
		{
			if (input[i] == '|' && input[i + 1] == '|')
			{
				printf("bash: syntax error near unexpected token `%c\'\n", input[i]);
				free(cleaned);
				return (NULL);
			}
			else if (input[i + 1] == input[i])
			{
				if ((input[i + 2] == input[i + 1]))
				{
					printf("bash: syntax error near unexpected token `%c\'\n", input[i]);
					free(cleaned);
					return (NULL);
				}
				else
				{
					cleaned[j++] = ' ';
					cleaned[j++] = input[i++];
					cleaned[j++] = input[i++];
					cleaned[j++] = ' ';
				}
			}
			else
			{
				cleaned[j++] = ' ';
				cleaned[j++] = input[i++];
				cleaned[j++] = ' ';
			}
		}
		else
			cleaned[j++] = input[i++];
	}
	cleaned[j] = '\0';
	return (cleaned);
}

/// @brief Logical operator spacing - Adding space after any 
// kind of logical operators to deal with input such as 
// ">outfile", "echo hello|echo hello".
// Output will be "> outfile", "echo hello | echo hello".
/// @param input Malloc-ed string from readline
/// @return Spaced string before and after every logical operator
char	*normalize_input(char *input)
{
	char *cleaned_input;
	int	len;

	len = strlen(input);
	cleaned_input = malloc(len * 2 + 1);
	if (!cleaned_input)
	{
		printf("Input allocation failed");
		free(input);
		exit (1);
	}
	cleaned_input = normalizing_check(input, cleaned_input);
	free(input);
	return (cleaned_input);
}

// int main()
// {
// 	char *source = malloc(19 + 1);
// 	char *normalized = malloc(19 + 1);
// 	strcpy(source, "|pipe<out>>out<out");
// 	normalized = normalize_input(source);
// 	for (int i = 0; normalized[i]; i++)
// 	{
// 		printf("%c", normalized[i]);
// 	}
// 	printf("\n");
// 	free(normalized);
// 	free(source);
// }
