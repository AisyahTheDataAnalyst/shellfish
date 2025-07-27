# include "../include/minishell.h"

char *parameter_expansion(char *str, t_exc *exc);
char *value_expansion(char *param, char **env);
void get_value(char **param, char **env, char **result);
void check_quote(char **str, t_exc *exc);
void handle_quote(char quote, int *i, char *str, t_exc *exc, char **result);
void do_expansion(char *str_to_expand, t_exc *exc, char **result);
char *append_results(char *result, char *str_to_append);
bool is_valid_param_char(char letter);

// 1. check single/double quote- need to expand or not
// 2. parameter_expansion if got $
// 3. quote_removal
void expand_tokens(t_token *token, t_exc *exc)
{
	int i;

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
void check_quote(char **str, t_exc *exc)
{
	int i;
	int start;
	char *str_not_quote;
	char *result;

	i = 0;
	start = 0;
	str_not_quote = NULL;
	result = NULL;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '"' || (*str)[i] == '\'')
			handle_quote((*str)[i], &i, *str, exc, &result);
		else
		{
			start = i;
			while (!((*str)[i] == '"' || (*str)[i] == '\'') && (*str)[i] != '\0')
				i++;
			str_not_quote = ft_substr(*str, start, i - start);
			printf("str_not_quote: %s\n", str_not_quote);
			if (!str_not_quote)
				ft_putstr_fd("Failed to substr the string not inside the quote", 2);
			do_expansion(str_not_quote, exc, &result);
			printf("result: %s\n", result);
			free(str_not_quote);
		}
		printf("char[%d] = %c\n", i, (*str)[i]);
	}
	free(*str);
	(*str) = result;
}

void do_expansion(char *str_to_expand, t_exc *exc, char **result)
{
	char *expanded_str;

	expanded_str = NULL;
	expanded_str = parameter_expansion(str_to_expand, exc);
	if (expanded_str)
	{
		*result = append_results(*result, expanded_str);
		free(expanded_str);
	}
}

void handle_quote(char quote, int *i, char *str, t_exc *exc, char **result)
{
	int start;
	char *str_quote;

	start = 0;
	str_quote = NULL;
	start = ++(*i);
	printf("start: %d\n", start);
	printf("quote: [%c]\n", quote);
	while (str[(*i)] != quote && str[(*i)] != '\0')
		(*i)++;
	str_quote = ft_substr(str, start, (*i) - start);
	if (!str_quote)
		ft_putstr_fd("Failed to substr the string inside the quote", 2);
	if (quote == '"')
		do_expansion(str_quote, exc, result);
	else
		*result = append_results(*result, str_quote);
	free(str_quote);
	(*i)++;
}

char *append_results(char *result, char *str_to_append)
{
	char *temp;

	temp = NULL;
	if (result == NULL)
		result = ft_strdup("");
	temp = result;
	result = ft_strjoin(result, str_to_append);
	free (temp);
	// (str_to_append) = NULL;
	return(result);
}

char *parameter_expansion(char *str, t_exc *exc)
{
	char *param;
	char *result;
	char *after_expand;
	char *not_expand;
	int start;
	int j;

	param = NULL;
	result = NULL;
	after_expand = NULL;
	not_expand = NULL;
	start = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '$' && str[j + 1] == '?')
		{
			// printf("%d\n", exc->exit_code);
			return(ft_itoa(exc->exit_code));
		}
		if (str[j] == '$')
		{
			start = ++j;
			//printf("start: %d\n", start);
			while (str[j] != '$' && str[j] != '\0' && is_valid_param_char(str[j]))
				j++;
			//printf("len: %d\n", param_len);
			param = ft_substr(str, start, j - start);
			//printf("param before expansion: %s\n", param);
			if (param)
			{
				after_expand = value_expansion(param, exc->exec->envp_array);
				// printf("after_expand: %s\n", after_expand);
				free(param);
				param = NULL;
				if (after_expand)
				{	result = append_results(result, after_expand);
					// return(result);
					// free(after_expand);
					// after_expand = NULL;
				}
			}
		}
		else
		{
			start = j;
			while(str[j] != '$' && str[j] != '\0')
				j++;
			not_expand = ft_substr(str, start , j - start);
			// printf("not_expand: %s\n", not_expand);
			if (not_expand)
			{
				result = append_results(result, not_expand);
				// if (!result)
				// {
				// 	free(result);
				// 	result = NULL;
				// }
				free(not_expand);
			}
			// not_expand = NULL;
		}
		// printf("result: %s\n", result);
	}
	//if (result)
	//{
	//	free(str);  // Free the original string
	//	str = result;  // Make a copy
	//}
	return(result);
}

//check if the param is valid
bool is_valid_param_char(char letter)
{
	if (!(ft_isalnum(letter) || letter == '_'))
			return(false);
	return(true);
}

void get_value(char **param, char **env, char **result)
{
	char *value;
	char *temp;

	value = NULL;
	temp = NULL;
	value = value_expansion(*param, env);
	free(*param);
	*param = NULL;
	//printf("param after expansion: %s\n", value);
	if (value)
	{
		if (*result == NULL)
			*result = ft_strdup("");
		temp = *result;
		*result = ft_strjoin(*result, value);
		free(temp);
		//printf("joined: %s\n", *result);
		value = NULL;
	}
}

char *value_expansion(char *param, char **env)
{
	char *value;
	int i = 0;
	char var[100];

	value = NULL;
	// printf("param: %s\n", param);
	while(env[i])
	{
		int j = 0;
		while (env[i][j] != '=' && env[i][j] != '\0')
		{
			var[j] = env[i][j];
			j++;
		}
		var[j] = '\0';
		// printf("j: %d\n", j);
		// printf("var[%ld]: %s\n", ft_strlen(var), var);
		if (ft_strncmp(param, var, ft_strlen(var) + 1) == 0)
		{
			value = ft_strchr(env[i], '=') + 1;
			// printf("value: %s\n", value);
			return(value);
		}
		i++;
	}
	return (NULL);
}
