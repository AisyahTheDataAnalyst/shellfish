/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:01:38 by yelu              #+#    #+#             */
/*   Updated: 2025/06/27 15:33:42 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	word_array(t_data *data, char *element)
{
	if (data->word.word_count == 0)
	{
		data->word.array = first_malloc(element);
		if (!data->word.array)
		{
			// Free some shits
			exit (1);
		}
	}
	else
	{
		data->word.array = ft_realloc(data->word.array, data->word.word_count, element);
		if (!data->word.array)
		{
			// Free some shits
			exit (1);
		}
	}
	data->word.word_count++;
}
