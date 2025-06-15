/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:20:47 by yelu              #+#    #+#             */
/*   Updated: 2025/06/15 16:12:48 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*quote_check(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] && input[i] != '"')
			{
				if (input[i] == ' ')
					input[i] = 31;
				i++;
			}
			if (input[i] != '"')
			{
				ft_putstr_fd("Error: unmatched double quote\n", 2);
				free(input);
				exit (1);
			}
		}
		else if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
			{
				if (input[i] == ' ')
					input[i] = 31;
				i++;
			}
			if (input[i] != '\'')
			{
				ft_putstr_fd("Error: unmatched single quote\n", 2);
				free(input);
				exit (1);
			}
		}
		i++;
	}
	return (input);
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
