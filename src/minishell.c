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

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	char	*line;
	char	**basin;
	t_token	*data;

	while (1)
	{
		line = readline("$minishell: ");
		if (ft_strncmp(line, "exit", 4) == 0)
			break;
		printf("You entered %s\n", line);
		basin = ft_split(line, ' ');
		ft_bzero(&data, sizeof(t_token));
		init_token(basin);
		free(line);
	}
	return (0);
}

