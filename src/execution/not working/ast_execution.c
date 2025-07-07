/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:53:16 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ast_execution(t_exc *exc)
{
	if (exc->ast->token == TOKEN_PIPE)
		return (ast_pipe(exc));
	else if (is_redirection(exc->ast->token->token_type) == 1)
		return (ast_redirection(exc));
	else
		return (ast_word(exc));
}









