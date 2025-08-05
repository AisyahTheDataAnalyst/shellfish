/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hehe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:11:41 by wshee             #+#    #+#             */
/*   Updated: 2025/08/05 13:39:35 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 1. check single/double quote- need to expand or not
// 2. parameter_expansion if got $
// 3. quote_removal
void	expand_tokens(t_token *token, t_exc *exc)
{
	int		i;
	char	*result;
	t_token	*curr;
	int		size;

	result = NULL;
	while (token)
	{
		i = 0;
		while (token->basin_buff && token->basin_buff[i])
		{
			check_got_quote(token->basin_buff[i], exc, &result);
			free(token->basin_buff[i]);
			if (!result)
				result = ft_strdup("");
			token->basin_buff[i] = result;
			result = NULL;
			i++;
		}
		token = token->next;
	}
}

char	**skip_null_strings(char **basin_buff, int size)
{
	char	**new_basin_buff;
	int		i;
	int		j;

	new_basin_buff = malloc(sizeof(char *) * (size + 1));
	if (!new_basin_buff)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (basin_buff[i])
		{
			new_basin_buff[j] = ft_strdup(basin_buff[i]);
			j++;
		}
		i++;
	}
	new_basin_buff[j] = NULL;
	i = 0;
	while (i < size)
		free(basin_buff[i++]);
	free(basin_buff);
	return (new_basin_buff);
}

// if got quote
// 	search for quote open and closing
// 	substr the str inside the quote
// 	store in result
// if not quote
// 	append to result
void	check_got_quote(char *basin, t_exc *exc, char **result)
{
	int		i;
	char	*str_quote;

	i = 0;
	str_quote = NULL;
	while (basin[i] != '\0')
	{
		if (basin[i] == '"' || basin[i] == '\'')
		{
			i++;
			str_quote = handle_quote(basin[i - 1], &i, basin, exc);
		}
		else
			str_quote = handle_quote('\0', &i, basin, exc);
		if (str_quote)
		{
			*result = append_results(*result, str_quote);
			free(str_quote);
		}
	}
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

static void	word_split_helper(char *input, char *split, int *i, int *j)
{
	if ((*i) == 0 || (input[(*i) - 1] != ' ' && input[(*i) - 1] != '\t'
			&& input[(*i) - 1] != '\n'))
		split[(*j)] = input[(*i)];
	else if (input[(*i) - 1] == ' ' || input[(*i) - 1] == '\t'
		|| input[(*i) - 1] == '\n')
	{
		split[(*j)++] = ' ';
		split[(*j)] = input[(*i)];
	}
}

//expansion for quote and unquote
//if unquote - do word splitting on IFS character
// what is IFS ? - space, newline, tab
//if quoted do no do word spliting
char	*word_splitting(char *input)
{
	char	*splitted_input;
	int		i;
	int		j;

	i = 0;
	j = 0;
	splitted_input = (char *) malloc((ft_strlen(input) + 1) * sizeof(char));
	if (!splitted_input)
		ft_putstr_fd("Failed to malloc splitted input", 2);
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			word_split_helper(input, splitted_input, &i, &j);
			j++;
		}
		else if ((input[i] == ' ' || input[i] == '\t'
				|| input[i] == '\n') && input[i + 1] == '\0')
			splitted_input[j++] = ' ';
		i++;
	}
	splitted_input[j] = '\0';
	return (splitted_input);
}

static void	parameter_ex_helper(char *str, int *start, int *j, char **result)
{
	char	*not_expand;

	not_expand = NULL;
	(*start) = (*j);
	while (str[(*j)] != '$' && str[(*j)] != '\0')
		(*j)++;
	not_expand = ft_substr(str, (*start), (*j) - (*start));
	if (!not_expand)
		ft_putstr_fd("Failed to substr the string not expand", 2);
	*result = append_results(*result, not_expand);
	free(not_expand);
}

// check if the first character is $
// expand the parameter when it see $
// if not iterate throught the string and append the original string to result
// check if there is another $ that need to be expand
void	parameter_expansion(char *str, t_exc *exc, char **result, char quote)
{
	int		start;
	int		j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '$' && (str[j + 1] == '\0' || str[j + 1] == ' '))
		{
			*result = append_results(*result, "$");
			return ;
		}
		else if (str[j] == '$')
		{
			if (quote == '\0')
				exc->process->need_to_split = true;
			need_to_expand(str, &j, exc, result);
		}
		else
			parameter_ex_helper(str, &start, &j, result);
	}
	exc->process->need_to_split = false;
}

static char	*need_expand_helper(int *start, int *j, char *str, t_exc *exc)
{
	char	*param;
	char	*after_expand;

	param = NULL;
	after_expand = NULL;
	(*start) = (*j);
	while (str[(*j)] != '$' && str[(*j)] != '\0' && valid_param(str[(*j)]))
		(*j)++;
	param = ft_substr(str, (*start), (*j) - (*start));
	if (!param)
		ft_putstr_fd("Failed to substr the string param", 2);
	after_expand = value_expansion(param, exc->exec->envp_array, exc);
	free(param);
	return (after_expand);
}

//handle $? - exit code
//expand the parameter in env if got $
// stop the while loop when it sees another $
// return to the original string
void	need_to_expand(char *str, int *j, t_exc *exc, char **result)
{
	int		start;
	char	*after_expand;

	start = 0;
	after_expand = NULL;
	(*j)++;
	if (str[(*j)] == '?')
	{
		handle_exit_code(result, j, exc);
		return ;
	}
	else
	{
		after_expand = need_expand_helper(&start, j, str, exc);
		if (after_expand)
		{
			*result = append_results(*result, after_expand);
			if (exc->process->need_to_split == true)
				free(after_expand);
		}
	}
}
