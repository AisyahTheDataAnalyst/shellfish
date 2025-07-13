/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:07:05 by yelu              #+#    #+#             */
/*   Updated: 2025/07/13 18:04:24 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Colors prompt
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BLACK       "\033[1;30m"
# define WHITE       "\033[1;37m"
# define LIGHT_RED   "\033[0;91m"
# define LIGHT_GREEN "\033[0;92m"
# define LIGHT_YELLOW "\033[0;93m"
# define LIGHT_BLUE  "\033[0;94m"
# define LIGHT_MAGENTA "\033[0;95m"
# define LIGHT_CYAN  "\033[0;96m"
# define GRAY        "\033[0;90m"
# define COLOR "\033[0m"
# define RL_CYAN "\001\033[1;36m\002"
# define RL_COLOR "\001\033[0m\002"

# include "token.h"
# include "ast.h"

typedef struct s_data
{
	t_token	*token;
	t_ast	*root;
}	t_data;

#endif
