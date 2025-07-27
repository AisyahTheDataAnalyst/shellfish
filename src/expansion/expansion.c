/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:11:41 by wshee             #+#    #+#             */
/*   Updated: 2025/07/27 22:09:54 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 1. check single/double quote- need to expand or not
// 2. parameter_expansion if got $
// 3. quote_removal
void	expand_tokens(t_token *token, t_exc *exc)
{
	int	i;

	i = 0;
	while (token)
	{
		while (token->basin_buff && token->basin_buff[i])
		{
			check_quote(&token->basin_buff[i], exc);
			i++;
		}
		token = token->next;
	}
}

// if got quote
	// search for quote open and closing
	// substr the str inside the quote
	// store in result
// if not quote
	// append to result
void	check_quote(char **str, t_exc *exc)
{
	int		i;
	int		start;
	char	*result;

	i = 0;
	start = 0;
	result = NULL;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '"' || (*str)[i] == '\'')
		{
			i++;
			handle_quote((*str)[i - 1], &i, *str, exc, &result);
		}
		else
			handle_quote('\0', &i, *str, exc, &result);
		printf("result: %s\n", result);
	}
	free(*str);
	(*str) = result;
}

// void	do_expansion(char *str_to_expand, t_exc *exc, char **result)
// {
// 	char	*expanded_str;

// 	expanded_str = parameter_expansion(str_to_expand, exc);
// 	if (expanded_str)
// 	{
// 		*result = append_results(*result, expanded_str);
// 		free(expanded_str);
// 	}
// }

void	handle_quote(char quote, int *i, char *str, t_exc *exc, char **result)
{
	int		start;
	char	*str_quote;

	start = 0;
	str_quote = NULL;
	start = (*i);
	while (str[(*i)] != '"' && str[(*i)] != '\'' && str[(*i)] != '\0')
		(*i)++;
	str_quote = ft_substr(str, start, (*i) - start);
	printf("str_quote: %s\n", str_quote);
	if (!str_quote)
		ft_putstr_fd("Failed to substr the string inside the quote", 2);
	if (quote == '"' || quote == '\0')
		parameter_expansion(str_quote, exc, result);
		// do_expansion(str_quote, exc, result);
	else
		*result = append_results(*result, str_quote);
	free(str_quote);
	if (quote == '"' && quote == '\'')
		(*i)++;
}

//handle $? - exit code
//expand the parameter in env if got $
void	parameter_expansion(char *str, t_exc *exc, char **result)
{
	// char	*result;
	char	*not_expand;
	int		start;
	int		j;

	// result = NULL;
	not_expand = NULL;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '$')
			need_to_expand(str, &j, exc, result);
		else
		{
			start = j;
			while (str[j] != '$' && str[j] != '\0')
				j++;
			not_expand = ft_substr(str, start, j - start);
			if (!not_expand)
				ft_putstr_fd("Failed to substr the string not expand", 2);
			*result = append_results(*result, not_expand);
			free(not_expand);
		}
	}
	// return (result);
}

void	need_to_expand(char *str, int *j, t_exc *exc, char **result)
{
	int		start;
	char	*param;
	char	*after_expand;

	start = 0;
	param = NULL;
	after_expand = NULL;
	(*j)++;
	if (str[(*j)] == '?')
	{
		handle_exit_code(result, j, exc);
		return ;
	}
	else
	{
		start = (*j);
		while (str[(*j)] != '$' && str[(*j)] != '\0' \
			&& is_valid_param_char(str[(*j)]))
			(*j)++;
		param = ft_substr(str, start, (*j) - start);
		if (!param)
			ft_putstr_fd("Failed to substr the string param", 2);
		after_expand = value_expansion(param, exc->exec->envp_array);
		free(param);
		*result = append_results(*result, after_expand);
	}
}
