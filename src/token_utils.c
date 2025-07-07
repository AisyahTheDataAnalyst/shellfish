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

#include "../include/token.h"

void	free_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**first_malloc(t_data *data, char *element)
{
	char	**array;

	array = malloc(sizeof(char *) * 2);
	if (!array)
		token_free_and_exit(data, "Fatal error - First malloc failed");
	array[0] = ft_strdup(element);
	if (!array[0])
		token_free_and_exit(data, "Fatal error - First malloc failed");
	array[1] = NULL;
	return (array);
}

char	**ft_realloc(t_data *data, char **old_array, char *element)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc(sizeof(char *) * (data->word.count + 2));
	if (!new_array)
		token_free_and_exit(data, "Fatal error - Realloc failed");
	while (i < data->word.count)
	{
		new_array[i] = old_array[i];
		i++;
	}
	new_array[i] = ft_strdup(element);
	new_array[i + 1] = NULL;
	free(old_array);
	return (new_array);
}

// Initialize master struct
void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}

// Free array created up until then when malloc fails
void	token_free_and_exit(t_data *data, char *str)
{
	if (data->word.array)
	{
		free_arr(data->word.array);
	}
	if (data->split_array)
	{
		free_arr(data->split_array);
	}
	ft_putstr_fd(str, 2);
	exit(1);
}
