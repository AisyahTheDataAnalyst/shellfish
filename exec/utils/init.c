/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:55:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/18 19:44:49 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// $PATH env variable = PATH=....
// split = directory path (/usr/bin)
// splitted_path = full/absolute path (/usr/bin/ + ls) 
// void	get_splitted_path(t_list *exec, char *full_path)
void	get_splitted_path(t_list *exec)
{
	char	**split;
	int		split_count;
	int		i;
	char	*full_path;

	full_path = getenv("PATH");
	split = ft_split(full_path, ':');
	if (!split)
		exit(1);
	split_count = ft_wordcount(full_path, ':');
	exec->splitted_path = malloc(sizeof(char *) * (split_count + 1));
	if (!(exec->splitted_path))
	{
		free_double_array(split);
		exit(1);
	}
	i = 0;
	while (split[i] && i < split_count)
	{
		exec->splitted_path[i] = ft_strjoin(split[i], "/");
		i++;
	}
	exec->splitted_path[i] = NULL;
	free_double_array(split);
}

void	envp_to_envparray(char **envp, t_list *exec)
{
	size_t	size;
	int		i;

	size = ft_array_size(envp);
	exec->envp_array = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (envp[i])
	{
		exec->envp_array[i] = ft_strdup(envp[i]);
		i++;
	}
	exec->envp_array[i] = NULL;
}
