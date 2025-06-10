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
	char		*input;
	char		**basin;
	t_data		data;
	int i = 0;

	init_data(&data);
	while (1)
	{
		input = readline("$minishell: ");
		printf("You entered %s\n", input);
		input = normalize_input(input);
		printf("Cleaned: %s\n", input);
		basin = ft_split(input, ' ');
		while (basin[i])
		{
			printf("Basin[%d]: %s\n", i, basin[i]);
			i++;
		}
		printf("Basin[%d] = %s\n", i, basin[i] ? basin[i] : "NULL");
		i = 0;
		init_token(&data, basin);
		free_arr(basin);
		free(input);
	}
	return (0);
}
