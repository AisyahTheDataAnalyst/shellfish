/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:06:45 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/03 22:06:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		execution(t_ast *ast, t_exc *exc);
static int	is_redirection(int token_type);

void	execution(t_ast *ast, t_exc *exc)
{
	if (ast->token->token_type == TOKEN_PIPE)
		exec_pipe(ast, exc);
	else if (is_redirection(ast->token->token_type) == 1)
		exec_redirection(ast, exc);
	else
	{
		if (!ast->token->basin_buff)
			return ;

		while (ast->token->basin_buff[exc->process->av_counter] && \
ast->token->basin_buff[exc->process->av_counter][0] == '\0')
			exc->process->av_counter++;
		if (!ast->token->basin_buff[exc->process->av_counter])
		{
			ft_putendl_fd("Command '' not found", 2);
			exc->exit_code = CMD_NOT_FOUND;
			return ;
		}
		else
			exec_word(ast, exc);
	}
}

static int	is_redirection(int token_type)
{
	if (token_type == TOKEN_APPEND || token_type == TOKEN_HEREDOC || \
token_type == TOKEN_REDIRECT_OUT || token_type == TOKEN_REDIRECT_IN)
		return (1);
	return (0);
}
