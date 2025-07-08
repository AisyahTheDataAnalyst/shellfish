/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:01:38 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:25:30 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

void	word_array(t_data *data, char *element)
{
	if (data->word.count == 0)
	{
		data->word.array = first_malloc(data, element);
		if (!data->word.array)
			token_free_and_exit(data, "Fatal error - Word array failed");
	}
	else
	{
		data->word.array = ft_realloc(data, data->word.array, element);
		if (!data->word.array)
			token_free_and_exit(data, "Fatal error - Word array failed");
	}
	data->word.count++;
}
