# include "../include/minishell.h"

void parameter_expansion(char **str, char **env);
char *value_expansion(char *param, char **env);
void get_value(char *param, char **env, char **result);


void expand_tokens(t_token *token, char **env)
{
	while (token)
	{
		int i = 0;
        while (token->basin_buff && token->basin_buff[i])
        {
			//check single/double quote- need to expand or not
			parameter_expansion(&token->basin_buff[i], env);
			//handle exit code
			//tilde epansion(optional)
			//quote_removal
			printf("token[%d][%d]: %s\n", token->index, i, token->basin_buff[i]);
            i++;
        }
        token = token->next;
    }
}

//void check_need_expansion()

void parameter_expansion(char **str, char **env)
{
    char *param;
	char *result;
	int start;
	int j;

	param = NULL;
	result = NULL;
	start = 0;
	j = 0;
	while ((*str)[j] != '\0')
	{
		if ((*str)[j] == '$')
		{
			start = ++j;
			//printf("start: %d\n", start);
			while ((*str)[j] != '$' && (*str)[j] != '\0')
				j++;
			//printf("len: %d\n", param_len);
			param = ft_substr((*str), start, j - start);
			//printf("param before expansion: %s\n", param);
			get_value(param, env, &result);
		}
		else
			j++;
	}
	if (result)
	{
		free((*str));  // Free the original string
		(*str) = result;  // Make a copy
	}
}

void ft_free(char *str)
{
	free(str);
	str = NULL;
}

void get_value(char *param, char **env, char **result)
{
	char *value;
	char *temp;

	value = NULL;
	temp = NULL;
	value = value_expansion(param, env);
	free(param);
	param = NULL;
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

//void find_dollar_sign(char *str)
//{
//	int i;
//	char *start;

//	i = 0;
//	while (*str)
//	{
//		if (*str == '$')
//		{
//			str++;
//			start = str;
//			while (*str != '$')
//			{
//				i++;
//				return(str);
//			}
//		}
//		i++;
//	}
//}

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
			//printf("value: %s\n", value);
            return(value);
        }
        i++;
    }
    return (NULL);
}
