/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:50:08 by yelu              #+#    #+#             */
/*   Updated: 2025/06/12 21:19:26 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    check_input(char **basin)
{
	int i;
	int type;

	i = 0;
	while (basin[i])
	{
		type = check_token_type(basin[i]);
		if (type == TOKEN_PIPE)
		{
			if (i = 0 || basin[i + 1] == NULL)
			{
				ft_putstr_fd("bash: syntax error near unexpected token `|'", 2);
				// Free both input and basin
				exit (2);
			}
		}
		else if (type == TOKEN_APPEND || type == TOKEN_HEREDOC || type == TOKEN_REDIRECT_IN ||
			type == TOKEN_REDIRECT_OUT)
		{
			if (basin[i + 1] == NULL)
			{
				ft_putstr_fd("bash: syntax error near unexpected token `newline'", 2);
				// Free both input and basin
				exit (2);
			}
		}
		i++;
	}
}
