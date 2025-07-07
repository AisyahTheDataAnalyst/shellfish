/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:38:00 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// do i need to make redirections return something or void only? 
// coz in pipex, need to dup2 fd with stdout/stdin, so need int return
// discuss with wendy about to put all the multiple files in separate ll or 
// combine all in char **basin_buff - better
int	ast_redirection(t_exc *exc)
{
	if (exc->token->token_type == TOKEN_REDIRECT_IN)
		return (rd_in(exc));
	else if (exc->token->token_type == TOKEN_HEREDOC)
		return (rd_heredoc(exc));
	else if (exc->token->token_type == TOKEN_REDIRECT_OUT)
		return (rd_out(exc));
	else if (exc->token->token_type == TOKEN_APPEND)
		return (rd_append(exc));
}

