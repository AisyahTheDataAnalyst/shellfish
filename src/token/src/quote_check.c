/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:20:47 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:22:54 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

static int	double_quote(char *input, int *i)
{
	while (input[*i] && input[*i] != '"')
	{
		if (input[*i] == ' ')
			input[*i] = 31;
		(*i)++;
	}
	if (input[*i] != '"')
	{
		ft_putstr_fd("Error: unmatched double quote\n", 2);
		return (0);
	}
	return (1);
}

static int	single_quote(char *input, int *i)
{
		while (input[*i] && input[*i] != '\'')
		{
			if (input[*i] == ' ')
				input[*i] = 31;
			(*i)++;
		}
		if (input[*i] != '\'')
		{
			ft_putstr_fd("Error: unmatched single quote\n", 2);
			return (0);
		}
		return (1);
}

/// @brief Quote check - To check if there's any unclosed quotes.
// IE: An open double quote must be followed by another closed double quote.
// To prevent ft_split splitting spaced characters
// inside quotes (ie: echo "hello      " space must be preserved until expansion).
/// @param input "Malloc-ed string from readline"
int quote_check(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			if (!double_quote(input, &i))
				return (0);
		}
		else if (input[i] == '\'')
		{
			i++;
			if (!single_quote(input, &i))
				return (0);
		}
		i++;
	}
	return (1);
}

// int main()
// {
// 	char *names = malloc(16 + 1);
// 	strcpy(names, "\'hello    world");
// 	quote_check(names);
// 	for (int i = 0; names[i]; i++)
// 	{
// 	if (names[i] == 31)
// 		printf("[SPACE]");
// 	else
// 		printf("%c", names[i]);
// 	}
// 	printf("\n");
// 	free(names);
// }
