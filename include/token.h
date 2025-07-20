/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:03:46 by yelu              #+#    #+#             */
/*   Updated: 2025/04/28 10:03:46 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "minishell.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_data	t_data;

typedef enum token_type
{
	TOKEN_WORD, // argument or commands
	TOKEN_HEREDOC, // <<
	TOKEN_APPEND, // >>
	TOKEN_REDIRECT_IN, // <
	TOKEN_REDIRECT_OUT, // >
	TOKEN_PIPE, // |
	// token quotes
}	t_type;

typedef struct s_word_arr
{
	int		count;
	char	**array;
}	t_word_arr;

typedef struct s_token
{
	int				index;
	t_type			token_type;
	char			**basin_buff;
	struct s_token	*next;
}	t_token;

typedef struct s_input_info
{
	int			index;
	t_token		*token;
	t_word_arr	word;
	char		**split_array;
	char		*input;
}	t_input_info;

// ============================

// Tokenization

void	init_data(t_input_info *input, t_data *data);
int		init_tokens(t_data *data, t_input_info *b_token, char *input);
int		quote_check(t_input_info *input);
int		normalize_input(t_input_info *input);
t_type	check_token_type(char *basin);
int		check_input(char **basin);
void	create_token(t_input_info *input);
void	replace_space(char **array);

// Word Tokenization
t_token	*create_word_token(t_input_info *input);

// Pipe Tokenization
t_token	*create_pipe(t_input_info *input, int type);

// Redirection In Tokenization
t_token	*create_redirects(char *s1, t_input_info *input, int type);
void	word_array(t_input_info *input, char *element);

// Utils
void	free_arr(char **array);
char	**first_malloc(t_input_info *input, char *element);
char	**ft_realloc(t_input_info *input, char **old_array, char *element);
void	token_free_and_exit(t_input_info *input, char *str);
void	free_token_list(t_data *data);
void	quote_copy(char *input, char *cleaned, int *i, int *j);
// =============================

#endif