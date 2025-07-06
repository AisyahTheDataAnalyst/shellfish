/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:35:06 by yelu              #+#    #+#             */
/*   Updated: 2025/07/05 17:39:41 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_ast   *create_node(t_token *token)
{
	t_ast	*node;
	
	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->token = token;
	ft_memset(node, 0, sizeof(t_ast));
	return (node);
}
