/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:53:16 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/12 11:41:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		ast_execution(t_ast *ast, t_exc *exc);
static int	is_redirection(int token_type);

void	ast_execution(t_ast *ast, t_exc *exc)
{
	if (ast->token->token_type == TOKEN_PIPE)
	{
		// printf("into ast_pipe\n");
		ast_pipe(ast, exc);
	}
	else if (is_redirection(ast->token->token_type) == 1)
	{
		// printf("into ast_redirection\n");
		ast_redirection(ast, exc);
	}
	else
	{
		// printf("into ast_word\n");
		ast_word(ast, exc);
	}
}

static int	is_redirection(int token_type)
{
	if (token_type == TOKEN_APPEND || token_type == TOKEN_HEREDOC || \
token_type == TOKEN_REDIRECT_OUT || token_type == TOKEN_REDIRECT_IN)
		return (1);
	return (0);
}








