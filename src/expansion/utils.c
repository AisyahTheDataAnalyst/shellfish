/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:12:06 by wshee             #+#    #+#             */
/*   Updated: 2025/08/03 18:23:46 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*append_results(char *result, char *str_to_append)
{
	char	*temp;

	temp = NULL;
	if (result == NULL)
		result = ft_strdup("");
	temp = result;
	result = ft_strjoin(result, str_to_append);
	free (temp);
	return (result);
}

//convert int to str
void	handle_exit_code(char **result, int *j, t_exc *exc)
{
	char	*exit_code;

	exit_code = ft_itoa(exc->exit_code);
	*result = append_results(*result, exit_code);
	free(exit_code);
	(*j) += 1;
}

//check if the parameter character is valid in env
// if not valid character append the original character to the string
// without the dollar
bool	valid_param(char letter)
{
	if (!(ft_isalnum(letter) || letter == '_'))
		return (false);
	return (true);
}

// if need to expand, find the value of the parameter in env
// append to the result if got value
// void	get_value(char **param, char **env, char **result, t_exc *exc)
// {
// 	char	*value;
// 	char	*temp;

// 	value = NULL;
// 	temp = NULL;
// 	value = value_expansion(*param, env, exc);
// 	free(*param);
// 	*param = NULL;
// 	if (value)
// 	{
// 		if (*result == NULL)
// 			*result = ft_strdup("");
// 		temp = *result;
// 		*result = ft_strjoin(*result, value);
// 		free(temp);
// 		value = NULL;
// 	}
// }

// store the param before = in the env in a temp arr
// compare with the user input param
// get the value after =
char	*value_expansion(char *param, char **env, t_exc *exc)
{
	char	*value;
	// char	*return_value;
	int		i;
	int		j;
	char	var[100];

	value = NULL;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j] != '\0')
		{
			var[j] = env[i][j];
			j++;
		}
		var[j] = '\0';
		if (ft_strncmp(param, var, ft_strlen(var) + 1) == 0)
		{
			value = ft_strchr(env[i], '=') + 1;
			// return_value = ft_strdup(value);
			if (exc->process->need_to_split == true)
				value = word_splitting(value);
			return (value);
		}
		i++;
	}
	return (NULL);
}
