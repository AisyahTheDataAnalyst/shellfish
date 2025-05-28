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
    TOKEN_PIPE, // |
    TOKEN_REDIRECT_IN, // <
    TOKEN_REDIRECT_OUT, // >
    TOKEN_APPEND, // >>
    TOKEN_HEREDOC, // <<
} t_type;

typedef struct s_token
{
    int index;
    t_type token_type;
    char **basin_buff;
    struct s_token *next;
} t_token;

// Tokenization
void    init_token(char **basin);

#endif
