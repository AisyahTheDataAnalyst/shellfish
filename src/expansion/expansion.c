# include "../include/minishell.h"

//TODO: solve memoery leak
//TODO: handle exit code (get from the execution struct)
char *parameter_expansion(char *str, t_exc *exc);
char *value_expansion(char *param, char **env);
void get_value(char **param, char **env, char **result);
void handle_quote(char **str, t_exc *exc);
char *append_results(char *result, char *str_to_append);
bool is_valid_param_char(char letter);

void expand_tokens(t_token *token, t_exc *exc)
{
	while (token)
	{
		int i = 0;
        while (token->basin_buff && token->basin_buff[i])
        {
			// check single/double quote- need to expand or not
            handle_quote(&token->basin_buff[i], exc);
            // parameter_expansion(&token->basin_buff[i], env);
			// handle exit code
			// tilde epansion(optional)
			// quote_removal
			// printf("token[%d][%d]: %s\n", token->index, i, token->basin_buff[i]);
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
void handle_quote(char **str, t_exc *exc)
{
    int i;
	int start;
	char *str_quote;
	char *str_not_quote;
	char quote;
	char *expanded_str;
	char *result;

    i = 0;
	start = 0;
	str_quote = NULL;
	expanded_str = NULL;
	result = NULL;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '"' || (*str)[i] == '\'')
		{
			quote = (*str)[i];
			start = ++i;
			// printf("quote %c\n", (*str)[start]);
			while ((*str)[i] != quote && (*str)[i] != '\0')
				i++;
			// printf("quote %c\n", (*str)[i]);
			str_quote = ft_substr((*str), start, i - start);
			if (!str_quote)
				printf("Failed to get the string inside the quote\n");
			// printf("inside quote: %s\n", str_quote);
			if (quote == '"')
			{
				expanded_str = parameter_expansion(str_quote, exc);
				// printf("expanded: %s\n", expanded_str);
				free(str_quote);
				if (expanded_str)
					result = append_results(result, expanded_str);
				expanded_str = NULL;
			}
			else
				result = append_results(result, str_quote);
			i++;
			// printf("result quote: %s\n", result);
		}
		else
		{
			start = i;
			while (!((*str)[i] == '"' || (*str)[i] == '\'') && (*str)[i] != '\0')
				i++;
			str_not_quote = ft_substr(*str, start, i - start);
			// printf("str_not_quote: %s\n", str_not_quote);
			expanded_str = parameter_expansion(str_not_quote, exc);
			free(str_not_quote);
			if (expanded_str)
				result = append_results(result, expanded_str);
			expanded_str = NULL;
		}
	}
	//if (result)
	//{
		free(*str);
		(*str) = result;
	//}
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
	(str_to_append) = NULL;
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
			printf("%d\n", exc->exit_code);
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
			after_expand = value_expansion(param, exc->exec->envp_array);
			// printf("after_expand: %s\n", after_expand);
			if(after_expand)
				result = append_results(result, after_expand);
			after_expand = NULL;
		}
		else
		{
			start = j;
			while(str[j] != '$' && str[j] != '\0')
				j++;
			not_expand = ft_substr(str, start , j - start);
			// printf("not_expand: %s\n", not_expand);
			if (not_expand)
				result = append_results(result, not_expand);
			not_expand = NULL;
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
