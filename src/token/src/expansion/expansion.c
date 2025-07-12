# include "../include/minishell.h"

void parameter_expansion(t_token *token, char **env);
char *value_expansion(char *param, char **env);

void expand_tokens(t_token *token, char **env)
{
    (void)env;
    parameter_expansion(token, env);
    //quote_removal
}

void parameter_expansion(t_token *token, char **env)
{
    (void)env;
    char *param;

    param = NULL;
    while (token)
    {
        int i = 0;
        while (token->basin_buff && token->basin_buff[i])
        {
            param = ft_strchr(token->basin_buff[i], '$');
            if (param)
            {
                param = value_expansion(param + 1, env);
                if(param)
                {
                    free(token->basin_buff[i]);  // Free the original string
                    token->basin_buff[i] = ft_strdup(param);  // Make a copy
                }
                // printf("After expand: %s\n", param);
            }
            // printf("param: %s\n", param);
            i++;
        }
        token = token->next;
    }   
}

char *value_expansion(char *param, char **env)
{
    char *value;
    int i = 0;
    
    // printf("param: %s\n", param);
    while(env[i])
    {
        if (ft_strncmp(param, env[i], ft_strlen(param)) == 0)
        {
            value = getenv(env[i]);
            if ((*param + ft_strlen(param) + 1) != '\0')
            {    
                value = ft_strjoin(value, param);
                printf("value: %s\n", value);
            }    
            return(value);
        }
        i++;
    }
    return (NULL);
}
