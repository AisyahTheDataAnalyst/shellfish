# include "../include/minishell.h"

char *parameter_expansion(char *str, char **env);
char *value_expansion(char *param, char **env);
void get_value(char **param, char **env, char **result);
void handle_quote(char **str, char **env);
char *append_results(char *result, char *str_to_append);
bool is_valid_param_char(char letter);

void expand_tokens(t_token *token, char **env)
{
	while (token)
	{
		int i = 0;
        while (token->basin_buff && token->basin_buff[i])
        {
			// check single/double quote- need to expand or not
            handle_quote(&token->basin_buff[i], env);
            // parameter_expansion(&token->basin_buff[i], env);
			// handle exit code
			// tilde epansion(optional)
			// quote_removal
			printf("token[%d][%d]: %s\n", token->index, i, token->basin_buff[i]);
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
void handle_quote(char **str, char **env)
{
    int i;
	int j;
	int start;
	char *str_quote;
	char *str_not_quote;
	char quote;
	char *expanded_str;
	char *result;

    i = 0;
	j = 0;
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
			printf("quote %c\n", (*str)[start]);
			while ((*str)[i] != quote && (*str)[i] != '\0')
				i++;
			printf("quote %c\n", (*str)[i]);
			str_quote = ft_substr((*str), start, i - start);
			if (!str_quote)
				printf("Failed to get the string inside the quote\n");
			printf("inside quote: %s\n", str_quote);
			if (quote == '"')
			{
				expanded_str = parameter_expansion(str_quote, env);
				printf("expanded: %s\n", expanded_str);
				free(str_quote);
				if (expanded_str)
					result = append_results(result, expanded_str);
				expanded_str = NULL;
			}
			else
				result = append_results(result, str_quote);
			i++;
			printf("result quote: %s\n", result);
		}
		else
		{
			start = i;
			while (!((*str)[i] == '"' || (*str)[i] == '\'') && (*str)[i] != '\0')
				i++;
			str_not_quote = ft_substr(*str, start, i - start);
			printf("str_not_quote: %s\n", str_not_quote);
			expanded_str = parameter_expansion(str_not_quote, env);
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
	//free (temp);
	(str_to_append) = NULL;
	return(result);
}

char *parameter_expansion(char *str, char **env)
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
		if (str[j] == '$')
		{
			start = ++j;
			//printf("start: %d\n", start);
			while (str[j] != '$' && str[j] != '\0' && is_valid_param_char(str[j]))
				j++;
			//printf("len: %d\n", param_len);
			param = ft_substr(str, start, j - start);
			//printf("param before expansion: %s\n", param);
			after_expand = value_expansion(param, env);
			printf("after_expand: %s\n", after_expand);
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
			printf("not_expand: %s\n", not_expand);
			if (not_expand)
				result = append_results(result, not_expand);
			not_expand = NULL;
		}
		printf("result: %s\n", result);
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
	//int i;

	//i = 0;
	//// check if is a valid starting char (must be alpha or _ only)
	//if (!ft_isalpha(str[i]) && !(str[i] == '_'))
	//	return(false);
	//// the following char can be alpha, number or _
	//while (str[i])
	//{
	//	if (!(ft_isalnum(str[i]) || str[i] == '_'))
	//		return(false);
	//	i++;
	//}
	if (!(ft_isalnum(letter) || letter == '_'))
			return(false);
	return(true);
}

//void parameter_expansion_first_try(char **str, char **env)
//{
//    char *param;
//	char *result;
//	int start;
//	int j;
//	bool expand;

//	param = NULL;
//	result = NULL;
//	start = 0;
//	j = 0;
//	expand = false;
//	while ((*str)[j] != '\0')
//	{
//		//printf("str[%d] = %c\n", j, (*str)[j]);
//		if ((*str)[j] == '"' || (*str)[j] == '\'')
//		{
//			//if ((*str)[j] == '$')
//			//{
//			++j;
//			printf("j = %d\n", j);
//			//	handle_quote(*str, &j, (*str)[j], env);
//			//}
//			//else
//			//handle_quote(*str, &j, (*str)[j], env);
//		}
//	// handle quote in str
//	// create a new function
//	// figure out how to handle both with quote or without quote
//		//if ((*str)[j] == '"' || (*str)[j] == '\'' || (*str)[j] == '$')
//		//{
//		//	if ((*str)[j] == '$')
//		//		handle_quote(*str, j, (*str)[j]);
//		//	else
//		//		handle_quote(*str, ++j, (*str)[j]);
//		//}
//		//while ((*str)[j] != '\0' && ((*str)[j] != quote))
//		//{
//		//	if ((*str)[j] == '$' && quote == '"' || quote == '$')
//		//	{
//		//		start = ++j;
//		//		while (validEnvironVariableChar)
//		//			++j;
//		//		param = ft_substr((*str), start, j - start);
//		//		get_value(param, env, &result);
//		//	}
//		//	++j;
//		//}
//	// end

//		//if ((*str)[j] == '$')
//		//{
//		//	start = ++j;
//		//	//printf("start: %d\n", start);
//		//	while ((*str)[j] != '$' && (*str)[j] != '\0')
//		//		j++;
//		//	//printf("len: %d\n", param_len);
//		//	param = ft_substr((*str), start, j - start);
//		//	//printf("param before expansion: %s\n", param);
//		//	get_value(param, env, &result);
//		//}
//		else
//			j++;
//	}
//	if (result)
//	{
//		free((*str));  // Free the original string
//		(*str) = result;  // Make a copy
//	}
//}

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

    printf("param: %s\n", param);
    while(env[i])
    {
		if (ft_strncmp(param, env[i], ft_strlen(param)) == 0)
        {
            value = getenv(param);
			printf("value: %s\n", value);
            return(value);
        }
        i++;
    }
    return (NULL);
}
