/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:12:06 by wshee             #+#    #+#             */
/*   Updated: 2025/08/10 13:37:08 by aimokhta         ###   ########.fr       */
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

//check if the parameter character is valid in env
// if not valid character append the original character to the string
// without the dollar
bool	valid_param(char letter)
{
	if (!(ft_isalnum(letter) || letter == '_'))
		return (false);
	return (true);
}

// store the param before = in the env in a temp arr
// compare with the user input param
// get the value after =
// maximum size limits for environment variable names in Linux = 131072
char	*value_expansion(char *param, char **env, t_exc *exc)
{
	char	*value;
	int		i;
	int		j;
	char	var[131072];

	value = NULL;
	i = -1;
	while (env[++i])
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
			if (exc->process->need_to_split == true)
				value = word_splitting(value);
			return (value);
		}
	}
	return (NULL);
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
		return (ft_putendl_fd("Failed to malloc splitted input", 2), NULL);
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
