/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:26:11 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:18:25 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_unset(char **args, t_data *data);
static void	unset_array(char **av, t_list *exec);
static char	**unset_array_marking(char **av, t_list *exec);
static char	**unset_array_marking_helper(char **av, t_list *exec, char **temp);
static int	mark_count(char **temp);

void	bi_unset(char **args, t_data *data)
{
	if (!args[1])
	{
		data->exit_code = 0;
		return ;
	}
	if (!ft_strncmp(args[0], "unset", 6))
	{
		unset_array(args, data->exec);
		data->exit_code = 0;
	}
}

static void	unset_array(char **av, t_list *exec)
{
	char	**temp;
	int		i;
	int		j;
	int		count;

	temp = NULL;
	temp = unset_array_marking(av, exec);
	count = mark_count(temp);
	free_double_array(exec->envp_array);
	exec->envp_array = malloc(sizeof(char *) * (count + 1));
	if (!exec->envp_array)
		return ;
	i = 0;
	j = 0;
	while (temp[i])
	{
		if (ft_strncmp("!", temp[i], 1) != 0)
			exec->envp_array[j++] = ft_strdup(temp[i]);
		i++;
	}
	exec->envp_array[j] = NULL;
	free_double_array(temp);
}

static char	**unset_array_marking(char **av, t_list *exec)
{
	int		i;
	char	**temp;

	i = ft_array_size(exec->envp_array);
	temp = malloc(sizeof(char *) * (i + 1));
	if (!temp)
		return (NULL);
	temp = unset_array_marking_helper(av, exec, temp);
	return (temp);
}

static char	**unset_array_marking_helper(char **av, t_list *exec, char **temp)
{
	int		i;
	int		j;
	bool	match;

	i = -1;
	while (exec->envp_array[++i])
	{
		match = false;
		j = 0;
		while (av[++j])
		{
			if (ft_strncmp(exec->envp_array[i], av[j], ft_strlen(av[j])) == 0
				&& exec->envp_array[i][ft_strlen(av[j])] == '=')
			{
				match = true;
				break ;
			}
		}
		if (match == true)
			temp[i] = ft_strjoin("!", exec->envp_array[i]);
		else
			temp[i] = ft_strdup(exec->envp_array[i]);
	}
	temp[i] = NULL;
	return (temp);
}

static int	mark_count(char **temp)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (temp[i])
	{
		if (ft_strncmp("!", temp[i], 1) != 0)
			count++;
		i++;
	}
	return (count);
}
