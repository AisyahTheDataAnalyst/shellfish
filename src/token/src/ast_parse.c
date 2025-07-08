/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:35:38 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:22:24 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"

t_ast	*init_ast(t_data *data)
{
	data->root = parse_pipe(data->token);
	if (!data->root)
	{
		printf("Error - Tree creation error!")
		return (0);
	}
	return (1);
}


t_ast	*parse_pipe(t_token *token)
{
	t_ast	*left;

	left = parse_redirection(token);
	if (!left)
		return (NULL);
	return (right_pipe(left, token));
}

t_ast	*parse_word(t_token *token)
{
	t_ast	*node;
	
	if (!token)
		return (NULL);
	node = NULL;
	if (token->token_type == TOKEN_WORD)
	{
		node = create_node(token);
		if (!node)
			return (NULL);
	}
	return (node);
}

t_ast	*parse_redirection(t_token *token)
{
	t_ast	*node;
	
	if (!token)
		return (NULL);
	if (token->type >= TOKEN_HEREDOC && token->token_type <= TOKEN_REDIRECT_OUT)
	{
		node = create_node(token);
		if (!node)
			return (NULL);
		node->left = parse_redirection(token->next);
	}
	return (node);
}
