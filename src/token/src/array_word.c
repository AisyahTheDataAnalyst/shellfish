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

void	word_array(t_input_info *input, char *element)
{
	if (input->word.count == 0)
	{
		input->word.array = first_malloc(input, element);
		if (!input->word.array)
			token_free_and_exit(input, "Fatal error - Word array failed");
	}
	else
	{
		input->word.array = ft_realloc(input, input->word.array, element);
		if (!input->word.array)
			token_free_and_exit(input, "Fatal error - Word array failed");
	}
	input->word.count++;
}
