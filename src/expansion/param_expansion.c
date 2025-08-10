/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:35:57 by wshee             #+#    #+#             */
/*   Updated: 2025/08/10 13:34:43 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parameter_ex_helper(char *str, int *start, int *j, char **result)
{
	char	*not_expand;

	not_expand = NULL;
	(*start) = (*j);
	while (str[(*j)] != '$' && str[(*j)] != '\0')
		(*j)++;
	not_expand = ft_substr(str, (*start), (*j) - (*start));
	if (!not_expand)
		return (ft_putendl_fd("Substr failed for not expand", 2));
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
		return (ft_putendl_fd("Substr failed for param", 2), NULL);
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

//convert int to str
void	handle_exit_code(char **result, int *j, t_exc *exc)
{
	char	*exit_code;

	exit_code = ft_itoa(exc->exit_code);
	*result = append_results(*result, exit_code);
	free(exit_code);
	(*j) += 1;
}
