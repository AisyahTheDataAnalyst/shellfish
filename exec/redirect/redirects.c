/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:38:00 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:18:35 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// do i need to make redirections return something or void only? 
// coz in pipex, need to dup2 fd with stdout/stdin, so need int return
// discuss with wendy about to put all the multiple files in separate ll or 
// combine all in char **basin_buff - better
int	redirects(t_token *token)
{
	int	fd;

	fd = 0;
	if (token->token_type == TOKEN_REDIRECT_IN)
		fd = rd_in(token);
	else if (token->token_type == TOKEN_REDIRECT_OUT)
		fd = rd_out(token);
	else if (token->token_type == TOKEN_HEREDOC)
		fd = rd_heredoc(token);
	else if (token->token_type == TOKEN_APPEND)
		fd = rd_append(token);
	return (fd);
}
//later , where it will call this function
// if (redirects(token) == -1)
// 	freeing(exec);