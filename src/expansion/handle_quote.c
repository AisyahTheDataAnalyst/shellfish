/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:47:28 by wshee             #+#    #+#             */
/*   Updated: 2025/08/08 20:53:21 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// if got quote
// 	search for quote open and closing
// 	substr the str inside the quote
// 	store in result
// if not quote
// 	append to result
void	check_got_quote(char **str, t_exc *exc)
{
	char	*result;
	bool	has_quotes;

	has_quotes = ori_string_has_quotes(*str);
	result = result_for_check_got_quote(str, exc);
	if (!result && has_quotes == true)
		result = ft_strdup("");
	free(*str);
	(*str) = result;
}

char	*result_for_check_got_quote(char **str, t_exc *exc)
{
	int		i;
	char	*str_quote;
	char	*result;

	i = 0;
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
		if (str_quote)
		{
			result = append_results(result, str_quote);
			free(str_quote);
		}
	}
	return (result);
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
		parameter_expansion(str_quote, exc, &result, quote);
	else
		result = append_results(result, str_quote);
	free(str_quote);
	if (quote == '"' || quote == '\'')
		(*i)++;
	return (result);
}

bool	ori_string_has_quotes(char *str)
{
	return (str && (ft_strchr(str, '\'') || ft_strchr(str, '"')));
}
