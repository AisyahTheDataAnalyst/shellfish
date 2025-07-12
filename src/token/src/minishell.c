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

#include "../include/token.h"
#include "../include/ast.h"
#include "../include/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)env;
	char		*input;
	t_input_info	b_input;
	t_data		data;

	if (argc == 1)
	{
		while (1)
		{
			input = readline("$minishell: ");
			if (!init_tokens(&data, &b_input, input))
				continue ;
			if (!init_ast(&data))
				continue ;
			if (data.token)
				free_token_list(&data);
			if (data.root)
				free_ast(&data);
			continue ;
		}
		ft_putstr_fd("No such files or directory", 2);
	}
	return (0);
}
