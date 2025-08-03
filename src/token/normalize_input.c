/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:02:26 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:22:45 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

static int	syntax_error(char *input, char *cleaned, char c)
{
	ft_putstr_fd("shellfish: syntax error near unexpected token ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\n", 2);
	free(cleaned);
	free(input);
	return (0);
}

static void	add_with_space(char *input, char *cleaned, int *i, int *j)
{
	cleaned[(*j)++] = ' ';
	cleaned[(*j)++] = input[(*i)++];
	cleaned[(*j)++] = ' ';
}

static int	handle_operator(char *input, char *cleaned, int *i, int *j)
{
	if (input[*i] == '|' && input[(*i) + 1] == '|')
		return (syntax_error(input, cleaned, '|'));
	else if (input[(*i) + 1] == input[*i])
	{
		if (input[(*i) + 2] == input[(*i) + 1])
			return (syntax_error(input, cleaned, input[*i]));
		cleaned[(*j)++] = ' ';
		cleaned[(*j)++] = input[(*i)++];
		cleaned[(*j)++] = input[(*i)++];
		cleaned[(*j)++] = ' ';
	}
	else
		add_with_space(input, cleaned, i, j);
	return (1);
}

static char	*normalizing_check(char *input, char *cleaned, t_exc *exc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		quote_copy(input, cleaned, &i, &j);
		if (input[i] == '>' || input[i] == '<' || input[i] == '|')
		{
			if (!handle_operator(input, cleaned, &i, &j))
			{
				exc->exit_code = 2;
				return (NULL);
			}
		}
		else
			cleaned[j++] = input[i++];
	}
	cleaned[j] = '\0';
	free(input);
	return (cleaned);
}

/// @brief Logical operator spacing - Adding space after any 
// kind of logical operators to deal with input such as 
// ">outfile", "echo hello|echo hello".
// Output will be "> outfile", "echo hello | echo hello".
/// @param input Malloc-ed string from readline
/// @return Spaced string before and after every logical operator
int	normalize_input(t_input_info *data, t_exc *exc)
{
	char	*cleaned_input;
	int		len;

	len = strlen(data->input);
	cleaned_input = malloc(len * 3 + 1);
	if (!cleaned_input)
	{
		ft_putstr_fd("Input allocation failed", 2);
		free(data->input);
		exit (1);
	}
	data->input = normalizing_check(data->input, cleaned_input, exc);
	if (!data->input)
		return (0);
	return (1);
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