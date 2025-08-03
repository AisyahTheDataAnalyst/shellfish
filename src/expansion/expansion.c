/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:11:41 by wshee             #+#    #+#             */
/*   Updated: 2025/08/03 14:08:38 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 1. check single/double quote- need to expand or not
// 2. parameter_expansion if got $
// 3. quote_removal
void	expand_tokens(t_token *token, t_exc *exc)
{
	int	i;

	while (token)
	{
		i = 0;
		while (token->basin_buff && token->basin_buff[i])
		{
			check_got_quote(&token->basin_buff[i], exc);
			i++;
		}
		token = token->next;
	}
}

// if got quote
// 	search for quote open and closing
// 	substr the str inside the quote
// 	store in result
// if not quote
// 	append to result
void	check_got_quote(char **str, t_exc *exc)
{
	int		i;
	int		start;
	char	*str_quote;
	char	*result;

	i = 0;
	start = 0;
	str_quote = NULL;
	result = NULL;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '"' || (*str)[i] == '\'')
		{
			i++;
			str_quote = handle_quote((*str)[i - 1], &i, *str, exc);
		}
		else
			str_quote = handle_quote('\0', &i, *str, exc);
		// printf("str_quote:%s\n", str_quote);
		if (str_quote)
			result = append_results(result, str_quote);
		free(str_quote);
		// printf("result: %s\n", result);
	}
	free(*str);
	(*str) = result;
}

// search for the other quote pair if got quote
// if double quote or no quote - pass to expansion
// else if single quote append the result
// skip the quote character if is quote
char	*handle_quote(char quote, int *i, char *str, t_exc *exc)
{
	int		start;
	char	*str_quote;
	char	*result;

	start = (*i);
	str_quote = NULL;
	result = NULL;
	while (str[(*i)] != quote && str[(*i)] != '\0')
	{
		if (quote == '\0')
			if (str[(*i)] == '"' || str[(*i)] == '\'')
				break ;
		(*i)++;
	}
	str_quote = ft_substr(str, start, (*i) - start);
	if (!str_quote)
		ft_putstr_fd("Failed to substr the string inside the quote", 2);
	if (quote == '"' || quote == '\0')
		parameter_expansion(str_quote, exc, &result);
	else
		result = append_results(result, str_quote);
	free(str_quote);
	if (quote == '"' || quote == '\'')
		(*i)++;
	return (result);
}

// check if the first character is $
// expand the parameter when it see $
// if not iterate throught the string and append the original string to result
// check if there is another $ that need to be expand
void	parameter_expansion(char *str, t_exc *exc, char **result)
{
	char	*not_expand;
	int		start;
	int		j;

	not_expand = NULL;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '$' && (str[j + 1] == '\0' || str[j + 1] == ' '))
		{
			*result = append_results(*result, "$");
			return ;
		}
		else if (str[j] == '$')
			need_to_expand(str, &j, exc, result);
		else
		{
			start = j;
			while (str[j] != '$' && str[j] != '\0')
				j++;
			not_expand = ft_substr(str, start, j - start);
			// printf("not_expand: %s\n", not_expand);
			if (!not_expand)
				ft_putstr_fd("Failed to substr the string not expand", 2);
			*result = append_results(*result, not_expand);
			free(not_expand);
		}
		// printf("param_expand_result: %s\n", *result);
	}
}

//handle $? - exit code
//expand the parameter in env if got $
// stop the while loop when it sees another $
// return to the original string
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
		while (str[(*j)] != '$' && str[(*j)] != '\0' && valid_param(str[(*j)]))
			(*j)++;
		param = ft_substr(str, start, (*j) - start);
		if (!param)
			ft_putstr_fd("Failed to substr the string param", 2);
		after_expand = value_expansion(param, exc->exec->envp_array);
		// printf("after_expand: %s\n", after_expand);
		free(param);
		if(after_expand)
			*result = append_results(*result, after_expand);
	}
}
