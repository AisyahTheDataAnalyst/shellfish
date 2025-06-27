/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:50:08 by yelu              #+#    #+#             */
/*   Updated: 2025/06/27 23:09:14 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_input(char **basin)
{
	int	i;
	int	type;
	int	next_type;

	i = 0;
	while (basin[i])
	{
		type = check_token_type(basin[i]);
		if (type == TOKEN_PIPE)
		{
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
		}
		else if (type == TOKEN_APPEND || type == TOKEN_HEREDOC || type == TOKEN_REDIRECT_IN ||
			type == TOKEN_REDIRECT_OUT)
		{
			if (basin[i + 1] == NULL)
			{
				ft_putstr_fd("bash: syntax error near unexpected token `newline'\n", 2);
				return (0);
			}
			next_type = check_token_type(basin[i + 1]);
			if (next_type == TOKEN_APPEND || next_type == TOKEN_HEREDOC || next_type == TOKEN_REDIRECT_IN ||
			next_type == TOKEN_REDIRECT_OUT || next_type == TOKEN_PIPE)
			{
				ft_putstr_fd("bash: syntax error near unexpected token `newline'\n", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
