/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:03:46 by yelu              #+#    #+#             */
/*   Updated: 2025/04/28 10:03:46 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef enum token_type
{
    TOKEN_WORD, // argument or commands
    TOKEN_HEREDOC, // <<
    TOKEN_APPEND, // >>
    TOKEN_REDIRECT_IN, // <
    TOKEN_REDIRECT_OUT, // >
    TOKEN_PIPE, // |
} t_type;

// typedef struct s_word_arr
// {
//     int     word_count;
//     char    **array;
// } t_word_arr;

typedef struct s_token
{
    int index;
    t_type token_type;
    char **basin_buff;
    struct s_token *next;
} t_token;

// typedef struct s_ast
// {
//     t_node_type ast_type;
//     char **args;
//     char *filename;
//     struct s_ast *left;
//     struct s_ast *right;
// } t_ast;

typedef struct s_data
{
    int index;
    t_token     *token;
} t_data;

// ============================

// Tokenization
void    init_token(char **basin, t_data *data);
void	init_data(t_data *data);

// Pipe Tokenization
t_token	*create_pipe(t_data *data, int type);

// Redirection In Tokenization


// =============================


#endif
