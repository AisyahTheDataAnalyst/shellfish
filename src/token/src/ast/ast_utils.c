/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:35:06 by yelu              #+#    #+#             */
/*   Updated: 2025/07/07 14:22:30 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/token.h"
#include "../include/ast.h"
#include "../include/minishell.h"

t_ast	*create_node(t_token *token)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(t_ast));
	node->token = token;
	return (node);
}

void	free_tree(t_ast *ptr)
{
	if (!ptr)
		return ;
	free_tree(ptr->left);
	free_tree(ptr->right);
	free(ptr);
}

void	free_ast(t_data *data)
{
	free_tree(data->root);
	data->root = NULL;
}

t_ast	*attached(t_token *token)
{
	t_ast	*word;
	t_ast	*ptr;
	t_ast	*temp_ptr;

	word = parse_word(token);
	if (!word)
		return (NULL);
	ptr = parse_redirection(token->next);
	if (ptr)
	{
		temp_ptr = ptr;
		while (temp_ptr->left)
			temp_ptr = temp_ptr->left;
		temp_ptr->left = word;
		return (ptr);
	}
	else
		return (word);
}
