# include "../include/minishell.h"

void parameter_expansion(t_token *token, char **env);
char *value_expansion(char *param, char **env);

void expand_tokens(t_token *token, char **env)
{
    parameter_expansion(token, env);
	//handle exit code
	//tilde epansion(optional)
    //quote_removal
}

void parameter_expansion(t_token *token, char **env)
{
    char *param;
	char *result;
	char *value;
	char *temp;
	int start;

    param = NULL;
	value = NULL;
	result = NULL;
	temp = NULL;
	start = 0;
    while (token)
    {
		int i = 0;
        while (token->basin_buff && token->basin_buff[i])
        {
			int j = 0;
			int param_len = 0;
			while (token->basin_buff[i][j] != '\0')
			{
				if (token->basin_buff[i][j] == '$')
				{
					j++;
					start = j;
					printf("start: %d\n", start);
					while (token->basin_buff[i][j] != '$' && token->basin_buff[i][j] != '\0')
					{
						//printf("[%c]\n", token->basin_buff[i][j]);
						param_len++;
						j++;
					}
					//printf("len: %d\n", param_len);
					param = ft_substr(token->basin_buff[i], start, param_len);
					printf("param before expansion: %s\n", param);
					value = value_expansion(param, env);
					free(param);
					printf("param after expansion: %s\n", value);
					if(value)
					{
						if (result == NULL)
						{
							result = ft_strdup("");
						}
						temp = result;
						result = ft_strjoin(result, value);
						free(temp);
						printf("joined: %s\n", result);
						//free(temp);
						param = NULL;
						value = NULL;
					}
				}
				//j++;
			}
			if (result)
			{
				//free(param);
				free(token->basin_buff[i]);  // Free the original string
				token->basin_buff[i] = ft_strdup(result);  // Make a copy
			}
			free(result);
			//free(temp);
            //param = ft_strchr(token->basin_buff[i], '$');
            //if (param)
            //{
            //    param = value_expansion(param + 1, env);
            //    if(param)
            //    {
            //        free(token->basin_buff[i]);  // Free the original string
            //        token->basin_buff[i] = ft_strdup(param);  // Make a copy
            //    }
            //    // printf("After expand: %s\n", param);
            //}
            // printf("param: %s\n", param);
			printf("token[%d][%d]: %s\n", token->index, i, token->basin_buff[i]);
            i++;
        }
        token = token->next;
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
        //printf("env: %s\n", env[i]);
		if (ft_strncmp(param, env[i], ft_strlen(param)) == 0)
        {
            value = getenv(param);
			printf("value: %s\n", value);
            //if ((*param + ft_strlen(param) + 1) != '\0')
            //{
            //    value = ft_strjoin(value, param);
            //    printf("value: %s\n", value);
            //}
            return(value);
        }
        i++;
    }
    return (NULL);
}
