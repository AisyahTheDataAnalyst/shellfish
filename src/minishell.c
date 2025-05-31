/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:57:34 by yelu              #+#    #+#             */
/*   Updated: 2025/05/02 21:15:15 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char		*line;
	char		**basin;
	t_data		data;
	// int i = 0;

	init_data(&data);
	while (1)
	{
		line = readline("$minishell: ");
		if (ft_strncmp(line, "exit", 4) == 0)
			break;
		printf("You entered %s\n", line);
		basin = ft_split(line, ' ');
		init_token(basin, &data);
		// while (word_arr.array[i])
		// {
		// 	printf("Array now: %s", word_arr.array[i]);
		// 	i++;
		// }
		free(line);
	}
	return (0);
}
