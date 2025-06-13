/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:02:26 by yelu              #+#    #+#             */
/*   Updated: 2025/06/11 17:11:15 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*normalizing_check(char *input, char *cleaned)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	j = 0;
	while (input[i])
	{
		c = input[i];
		if ((c == '&' && input[i+1] == '&') || (c == '|' && input[i+1] == '|'))
		{
			ft_putstr_fd("-bash: command not found", 2);
			free(input);
			free(cleaned);
			exit(1);
		}
		else if (c == '>' || c == '<' || c == '|')
		{
			if (input[i + 1] == c)
			{
				if ((input[i + 2] == c))
				{
					ft_putstr_fd("bash: syntax error near unexpected token `", 2);
					write(2, &input[i], 2);
					ft_putstr_fd("'\n", 2);
					free(cleaned);
					free(input);
					exit (2);
				}
					cleaned[j++] = ' ';
					cleaned[j++] = input[i++];
					cleaned[j++] = input[i++];
					cleaned[j++] = ' ';
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

char	*normalize_input(char *input)
{
	char *cleaned_input;
	int	len;

	len = ft_strlen(input);
	cleaned_input = malloc(len * 2 + 1);
	if (!cleaned_input)
	{
		ft_putstr_fd("Input allocation failed", 2);
		free(cleaned_input);
		free(input);
		exit (1);
	}
	cleaned_input = normalizing_check(input, cleaned_input);
	free(input);
	return (cleaned_input);
}
