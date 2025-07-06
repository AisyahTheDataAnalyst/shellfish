/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:54:16 by yelu              #+#    #+#             */
/*   Updated: 2025/06/04 11:54:16 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**first_malloc(char *element)
{
	char	**array;

	array = malloc(sizeof(char *) * 2);
	if (!array)
	{
		// Free the shits
		exit (1);
	}
	array[0] = ft_strdup(element);
	if (!array[0])
	{
		// Free the shits
		free(array);
		exit (1);
	}
	array[1] = NULL;
	return (array);
}

char	**ft_realloc(char **old_array, int count, char *element)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc(sizeof(char *) * (count + 2));
	if (!new_array)
	{
		// Free some shits
		exit (1);
	}
	while (i < count)
	{
		new_array[i] = old_array[i];
		i++;
	}
	new_array[i] = ft_strdup(element);
	new_array[i + 1] = NULL;
	free(old_array);
	return (new_array);
}

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}
