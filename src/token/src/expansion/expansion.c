# include "../include/minishell.h"

void parameter_expansion(char *str, int *j, char quote, char **env);
char *value_expansion(char *param, char **env);
void get_value(char **param, char **env, char **result);
void handle_quote(char *str, char **env);

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

void handle_quote(char *str, char **env)
{
    int i;

    i = 0;
    //search for double quote - expand
    if (str[i] == '"')
    {
        // skip the first double quote
        i++;
        //do expansion on the string between double quote
        while(str[i] != '"')
        {
            if (str[i + 1] == '$')
                parameter_expansion(str, &i, &str[i], env);
            else
                append_token();
            i++;
        }
        //skip the second double quote
        i++;
    }
    //search for single quote - not expand
    else if (str[i] == '\'')
    {
        //skip the first single quote
        i++;
        while(str[i] != '\'')
            append_token();
        //skip the second single quote
        i++;
    }
    //if starts with $
    else if (str[i] == '$')
        parameter_expansion();
    else
        append_token();
}

void parameter_expansion(char *str, int *j, char quote, char **env)
{
    int start;
    char *param;
    char *result;

    start = 0;
    param = NULL;
    result = NULL;
    while ((str)[*j] == quote || (str)[(*j)] == '\0' || (str)[(*j)] == '$')
    {
        if ((str)[(*j)] == '$')
        {
            printf("Before ++(*j): %d\n", (*j));
            start = ++(*j);
            printf("start: %d\n", start);
            //printf("isalpha: %d\n", ft_isalpha(str[*j]));
            // check if is a valid starting char (must be alpha or _ only)
            if (!ft_isalpha((str)[(*j)]) && !((str)[(*j)] == '_'))
            {
                ft_putstr_fd("not a valid identifier\n", 2);
                exit(1);
            }
            // the following char can be alpha, number or _
            while (ft_isalnum((str)[(*j)]))
            {
                //|| (str)[(*j)] != '\0'
                (*j)++;
            }
            printf("start: %d, j = %d\n", start, *j);
            param = ft_substr((str), start, (*j) - start);
            //printf("param before expansion: %s\n", param);
            get_value(&param, env, &result);
            printf("str[%d]: %c\n", *j, str[*j]);
        }
        else
            (*j)++;
    }
}

void parameter_expansion_first_try(char **str, char **env)
{
    char *param;
	char *result;
	int start;
	int j;
	bool expand;

	param = NULL;
	result = NULL;
	start = 0;
	j = 0;
	expand = false;
	while ((*str)[j] != '\0')
	{
		//printf("str[%d] = %c\n", j, (*str)[j]);
		if ((*str)[j] == '"' || (*str)[j] == '\'')
		{
			//if ((*str)[j] == '$')
			//{
			++j;
			printf("j = %d\n", j);
			//	handle_quote(*str, &j, (*str)[j], env);
			//}
			//else
			handle_quote(*str, &j, (*str)[j], env);
		}
	// handle quote in str
	// create a new function
	// figure out how to handle both with quote or without quote
		//if ((*str)[j] == '"' || (*str)[j] == '\'' || (*str)[j] == '$')
		//{
		//	if ((*str)[j] == '$')
		//		handle_quote(*str, j, (*str)[j]);
		//	else
		//		handle_quote(*str, ++j, (*str)[j]);
		//}
		//while ((*str)[j] != '\0' && ((*str)[j] != quote))
		//{
		//	if ((*str)[j] == '$' && quote == '"' || quote == '$')
		//	{
		//		start = ++j;
		//		while (validEnvironVariableChar)
		//			++j;
		//		param = ft_substr((*str), start, j - start);
		//		get_value(param, env, &result);
		//	}
		//	++j;
		//}
	// end

		//if ((*str)[j] == '$')
		//{
		//	start = ++j;
		//	//printf("start: %d\n", start);
		//	while ((*str)[j] != '$' && (*str)[j] != '\0')
		//		j++;
		//	//printf("len: %d\n", param_len);
		//	param = ft_substr((*str), start, j - start);
		//	//printf("param before expansion: %s\n", param);
		//	get_value(param, env, &result);
		//}
		else
			j++;
	}
	if (result)
	{
		free((*str));  // Free the original string
		(*str) = result;  // Make a copy
	}
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
