/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:36:43 by yelu              #+#    #+#             */
/*   Updated: 2025/08/04 12:37:11 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	replace_space(char **basin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (basin[i])
	{
		j = 0;
		while (basin[i][j])
		{
			if (basin[i][j] == 31)
				basin[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	replace_tab(char *basin)
{
	int	i;
	char	quote;

	i = 0;
	quote = 0;
	while (basin[i])
	{
		if ((basin[i] == '"' || basin[i] == '\'') && quote == 0)
			quote = basin[i];
		else if (basin[i] == quote)
			quote = 0;
		else if (basin[i] == '\t' && quote == 0)
			basin[i] = ' ';
		i++;
	}
}

// For replace space function int main
// int main()
// {
// 	char *array[] = {
// 		strdup("Hello			World"),
// 		strdup("Bro			Hello"),
// 		NULL
// 	};
// 	for(int i = 0; array[i]; i++)
// 		printf("Before: %s\n", array[i]);
// 	replace_tab(array);
// 	for(int i = 0; array[i]; i++)
// 		printf("After: %s\n", array[i]);
// 	for (int i = 0; array[i]; i++)
// 		free(array[i]);
// }

// For replace tab int main
// int main()
// {
// 	char *str = strdup("Hello	World");
// 	printf("Before: %s\n", str);
// 	replace_tab(str);
// 	printf("After: %s\n", str);
// 	free(str);
// }
