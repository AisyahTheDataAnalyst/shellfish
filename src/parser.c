/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:35:38 by yelu              #+#    #+#             */
/*   Updated: 2025/06/17 17:04:25 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_ast   *create_ast(t_token *token)
{
	t_ast	*node;
	
	node = malloc(sizeof(t_ast));
	node->token = token;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int precedence(int tok) {
    if (tok == TOKEN_WORD)
        return (0);
    if (tok == TOKEN_HEREDOC || tok == TOKEN_REDIRECT_IN)
        return (1);
    if (tok == TOKEN_REDIRECT_OUT || tok == TOKEN_APPEND)
        return (2);
    if (tok == TOKEN_PIPE)
        return (3);
    return -1;
}
