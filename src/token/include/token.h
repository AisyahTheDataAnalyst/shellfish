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
	// token quotes
} t_type;

typedef struct s_word_arr
{
	int		count;
	char	**array;
} t_word_arr;

typedef struct s_token
{
	int index;
	t_type token_type;
	char **basin_buff;
	struct s_token *next;
} t_token;

typedef struct s_ast
{
	t_token     *token;
	struct s_ast *left;
	struct s_ast *right;
} t_ast;

typedef struct s_data
{
	int index;
	t_token     *token;
	t_ast		*root;
	t_word_arr  word;
	char		**split_array;
} t_data;

// ============================

// Tokenization

void	init_data(t_data *data);
int		quote_check(char *input);
char	*normalize_input(char *input);
t_type	check_token_type(char *basin);
int		check_input(char **basin);
void    init_token(t_data *data, char **basin);

// Word Tokenization
t_token *create_word_token(t_data *data);

// Pipe Tokenization
t_token	*create_pipe(t_data *data, int type);

// Redirection In Tokenization
t_token *create_redirects(char *s1, t_data *data, int type);
void	word_array(t_data *data, char *element);

// Utils
void    free_arr(char **array);
char	**first_malloc(t_data *data, char *element);
char	**ft_realloc(t_data *data, char **old_array, char *element);
void	token_free_and_exit(t_data *data, char *str);
// =============================

// Binary Tree

t_ast   *create_node(t_token *token);


#endif
