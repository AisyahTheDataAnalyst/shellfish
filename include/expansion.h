/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:42:44 by wshee             #+#    #+#             */
/*   Updated: 2025/08/05 12:43:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <stdbool.h>

typedef struct s_exc	t_exc;

void	expand_tokens(t_token *token, t_exc *exc);
void	parameter_expansion(char *str, t_exc *exc, char **result, char quote);
char	*word_splitting(char *input);
char	*value_expansion(char *param, char **env, t_exc *exc);
void	get_value(char **param, char **env, char **result, t_exc *exc);
void	check_got_quote(char **str, t_exc *exc);
char	*handle_quote(char quote, int *i, char *str, t_exc *exc);
char	*append_results(char *result, char *str_to_append);
bool	valid_param(char letter);
void	need_to_expand(char *str, int *j, t_exc *exc, char **result);
void	handle_exit_code(char **result, int *j, t_exc *exc);

///aisyah add
char	**skip_null_strings(char **basin_buff, int size);
bool	ori_string_has_quotes(char *str);

#endif