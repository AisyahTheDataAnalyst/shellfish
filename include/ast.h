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

# include "token.h"

typedef	struct	s_token	t_token;

typedef struct s_ast
{
	t_token     *token;
	struct s_ast *left;
	struct s_ast *right;
} t_ast;

// Binary tree creation

int		init_ast(t_data *data);
t_ast	*create_node(t_token *token);
t_ast	*attached(t_token *token);
t_ast	*parse_pipe(t_token *token);
t_ast	*parse_word(t_token *token);
t_ast	*parse_redirection(t_token *token);
t_ast	*right_pipe(t_ast *ptr, t_token *token);

// Free tree

void	free_ast(t_data *data);
void	free_tree(t_ast *ptr);

#endif