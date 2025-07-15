/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:38:00 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/15 12:36:58 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// do i need to make redirections return something or void only? 
// coz in pipex, need to dup2 fd with stdout/stdin, so need int return
// discuss with wendy about to put all the multiple files in separate ll or 
// combine all in char **basin_buff - better
void	ast_redirection(t_ast *ast, t_exc *exc)
{
	if (ast->token->token_type == TOKEN_REDIRECT_IN)
		rd_in(ast, exc);
	else if (ast->token->token_type == TOKEN_HEREDOC)
		rd_heredoc(ast, exc);
	else if (ast->token->token_type == TOKEN_REDIRECT_OUT)
		rd_out(ast, exc);
	else if (ast->token->token_type == TOKEN_APPEND)
		rd_append(ast, exc);
}
