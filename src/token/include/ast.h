/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:41:03 by yelu              #+#    #+#             */
/*   Updated: 2025/07/08 13:41:03 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include "../include/token.h"

typedef struct s_ast
{
	t_token     *token;
	struct s_ast *left;
	struct s_ast *right;
} t_ast;

// Binary Tree

t_ast   *create_node(t_token *token);


#endif