/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:35:44 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_redirection(int token_type)
{
	if (token_type == TOKEN_APPEND || token_type == TOKEN_HEREDOC || \
token_type == TOKEN_REDIRECT_OUT || token_type == TOKEN_REDIRECT_IN)
		return (1);
	return (0);
}

int	is_rd_output(t_token *token)
{
	if (token->token_type == TOKEN_REDIRECT_OUT)
		return (1);
	else if (token->token_type == TOKEN_APPEND)
		return (1);
	return (0);
}

int	is_rd_input(t_token *token)
{
	if (token->token_type == TOKEN_REDIRECT_IN)
		return (1);
	else if (token->token_type == TOKEN_HEREDOC)
		return (1);
	return (0);
}

