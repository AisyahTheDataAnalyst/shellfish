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
#include "../include/ast.h"
#include "../include/minishell.h"

int	init_ast(t_data *data)
{
	if (!data->token)
		return (0);
	data->root = parse_pipe(data->token);
	if (!data->root)
		return (0);
	return (1);
}

t_ast	*parse_pipe(t_token *token)
{
	t_ast	*ptr;

	ptr = attached(token);
	if (!ptr)
		return (NULL);
	return(right_pipe(ptr, token->next));
}

t_ast	*parse_word(t_token *token)
{
	t_ast	*word;

	if (!token)
		return (NULL);
	word = NULL;
	if (token->token_type == TOKEN_WORD)
	{
		word = create_node(token);
		if (!word)
			return (NULL);
	}
	return (word);
}

t_ast	*parse_redirection(t_token *token)
{
	t_ast	*r_nodes;

	if (!token)
		return (NULL);
	r_nodes = NULL;
	if (token->token_type >= TOKEN_HEREDOC && token->token_type <= TOKEN_REDIRECT_OUT)
	{
		r_nodes = create_node(token);
		if (!r_nodes)
			return (NULL);
		r_nodes->left = parse_redirection(token->next);
	}
	return (r_nodes);
}

t_ast	*right_pipe(t_ast *ptr, t_token *token)
{
	t_ast	*pipe;

	while (token && token->token_type != TOKEN_PIPE)
		token = token->next;
	if (!token)
		return (ptr);
	pipe = NULL;
	if (token && token->token_type == TOKEN_PIPE)
	{
		pipe = create_node(token);
		if (!pipe)
			return (free_tree(ptr), NULL);
		pipe->left = ptr;
		pipe->right = attached(token->next);
		ptr = pipe;
		pipe = right_pipe(ptr, token->next);
	}
	return (pipe);
}
