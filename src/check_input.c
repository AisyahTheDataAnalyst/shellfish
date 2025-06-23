/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:50:08 by yelu              #+#    #+#             */
/*   Updated: 2025/06/23 16:32:45 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_type check_token_type(char *basin)
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
			if ((i = 0) || (basin[i + 1] == NULL))
			{
				ft_putstr_fd("bash: syntax error near unexpected token `|'", 2);
				return (0);
			}
		}
		else if (type == TOKEN_APPEND || type == TOKEN_HEREDOC || type == TOKEN_REDIRECT_IN ||
			type == TOKEN_REDIRECT_OUT)
		{
			if (basin[i + 1] == NULL)
			{
				ft_putstr_fd("bash: syntax error near unexpected token `newline'", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

