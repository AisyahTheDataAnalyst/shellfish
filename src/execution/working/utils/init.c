/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:55:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:16:11 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// $PATH env variable = PATH=....
// split = directory path (/usr/bin)
// splitted_path = full/absolute path (/usr/bin/ + ls) 
// void	get_splitted_path(t_list *exec, char *full_path)
void	get_splitted_path(t_process *process)
{
	char	**split;
	int		split_count;
	int		i;
	char	*full_path;

	full_path = getenv("PATH");
	split = ft_split(full_path, ':');
	if (!split)
		return ;
	split_count = ft_wordcount(full_path, ':');
	process->splitted_path = malloc(sizeof(char *) * (split_count + 1));
	if (!(process->splitted_path))
	{
		free_double_array(split);
		return ;
	}
	i = 0;
	while (split[i] && i < split_count)
	{
		process->splitted_path[i] = ft_strjoin(split[i], "/");
		i++;
	}
	process->splitted_path[i] = NULL;
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

int	total_heredocs(t_token *token)
{
	t_token	*curr;
	int		total;

	curr = token;
	total = 0;
	while (curr)
	{
		if (curr->token_type == TOKEN_HEREDOC)
			total++;
		curr->next = curr;
	}
	return (total);
}
