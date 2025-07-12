/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:36:43 by yelu              #+#    #+#             */
/*   Updated: 2025/07/12 14:15:05 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

void	replace_space(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 31)
				array[i][j] = ' ';
			j++;
		}
		i++;
	}
}

// int main()
// {
// 	char *array[] = {
// 		strdup("Hello\x1FWorld"),
// 		strdup("Bro\x1FHello"),
// 		NULL
// 	};
// 	for(int i = 0; array[i]; i++)
// 		printf("%s\n", array[i]);
// 	replace_space(array);
// 	for(int i = 0; array[i]; i++)
// 		printf("%s\n", array[i]);
// 	for (int i = 0; array[i]; i++)
// 		free(array[i]);
// }
