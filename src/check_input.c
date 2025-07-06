/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:50:08 by yelu              #+#    #+#             */
/*   Updated: 2025/07/05 15:28:04 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	pipe_check(char **basin, int i)
{
	int	next_type;

	if ((i == 0) || (basin[i + 1] == NULL))
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		return (0);
	}
	next_type = check_token_type(basin[i + 1]);
	if (next_type == TOKEN_PIPE)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `|'\n", 2);
		return (0);
	}
	return (1);
}

static int	redirect_check(char **basin, int i)
{
	int	next_type;

	if (basin[i + 1] == NULL)
	{
		printf("bash: syntax error near unexpected token `%s'\n", basin[i]);
		return (0);
	}
	next_type = check_token_type(basin[i + 1]);
	if (next_type == TOKEN_APPEND || next_type == TOKEN_HEREDOC
		|| next_type == TOKEN_REDIRECT_IN
		|| next_type == TOKEN_REDIRECT_OUT || next_type == TOKEN_PIPE)
	{
		printf("bash: syntax error near unexpected token `%s'\n", basin[i]);
		return (0);
	}
	return (1);
}

/// @brief Check input - To check if there is input right after any redirections
// and if there are inputs before and after each pipe. Redirection operators
// must not followed by any kind of logical operators
// Invalid inputs: "< << infile", "< > outfile", "> >> outfile"
// "NULL | echo hello world", "echo hello | NULL".
/// @param basin  Splitted array.
/// @return Boolean, error message if invalid.
int	check_input(char **basin)
{
	int	i;
	int	type;

	i = 0;
	while (basin[i])
	{
		type = check_token_type(basin[i]);
		if (type == TOKEN_PIPE)
		{
			if (!pipe_check(basin, i))
				return (0);
		}
		else if (type == TOKEN_APPEND || type == TOKEN_HEREDOC
			|| type == TOKEN_REDIRECT_IN
			|| type == TOKEN_REDIRECT_OUT)
		{
			if (!redirect_check(basin, i))
				return (0);
		}
		i++;
	}
	return (1);
}
