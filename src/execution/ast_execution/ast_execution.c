/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:53:16 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/16 13:25:12 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		ast_execution(t_ast *ast, t_exc *exc);
static int	is_redirection(int token_type);

void	ast_execution(t_ast *ast, t_exc *exc)
{
	if (ast->token->token_type == TOKEN_PIPE)
	{
		printf("ast_pipe - basin_buff[0] = NULL\n");
		ast_pipe(ast, exc);
	}
	else if (is_redirection(ast->token->token_type) == 1)
	{
		printf("ast_redirection - basin_buff[0] = %s\n", ast->token->basin_buff[0]);
		ast_redirection(ast, exc);
	}
	else
	{
		if (!ast->token->basin_buff)
		{
			printf("basin buff is a NULL for token word\n");
			return ;
		}
		else
		{
			printf("ast_word - basin_buff[0] = %s\n", ast->token->basin_buff[0]);
			ast_word(ast, exc);
		}
	}
}

static int	is_redirection(int token_type)
{
	if (token_type == TOKEN_APPEND || token_type == TOKEN_HEREDOC || \
token_type == TOKEN_REDIRECT_OUT || token_type == TOKEN_REDIRECT_IN)
	{
		printf("it is a redirection\n");
		return (1);
	}
	printf("its not a redirection\n");
	return (0);
}
