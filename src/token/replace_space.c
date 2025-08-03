/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:36:43 by yelu              #+#    #+#             */
/*   Updated: 2025/08/03 18:59:21 by yelu             ###   ########.fr       */
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

void	replace_tab(char **basin)
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
			if ((basin[i][j] == '"' || basin[i][j] == '\'') && basin[i][j])
			{
				j++;
				while ((basin[i][j] != '"' || basin[i][j] != '\'') && basin[i][j])
					j++;
			}
			else if (basin[i][j] == '\t')
			{
				basin[i][j] = ' ';
				j++;
			}
		}
		i++;
	}
}

int main()
{
	char *array[] = {
		strdup("Hello			World"),
		strdup("Bro			Hello"),
		NULL
	};
	for(int i = 0; array[i]; i++)
		printf("Before: %s\n", array[i]);
	replace_tab(array);
	for(int i = 0; array[i]; i++)
		printf("After: %s\n", array[i]);
	for (int i = 0; array[i]; i++)
		free(array[i]);
}
