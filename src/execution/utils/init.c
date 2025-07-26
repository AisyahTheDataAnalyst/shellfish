/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:55:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/26 15:35:10 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*get_full_path(t_list *exec);

// $PATH env variable = PATH=....
// split = directory path (/usr/bin)
// splitted_path = full/absolute path (/usr/bin/ + ls) 
// void	get_splitted_path(t_list *exec, char *full_path)
void	get_splitted_path(t_process *process, t_list *exec)
{
	char	**split;
	int		split_count;
	int		i;
	char	*full_path;

	full_path = get_full_path(exec);
	if (!full_path)
	{
		process->splitted_path = NULL;
		return ;
	}
	split = ft_split(full_path, ':');
	fprintf(stderr, "split[0]: %s\n", split[0]);
	split_count = ft_wordcount(full_path, ':');
	fprintf(stderr, "split_count: %d\n", split_count);
	process->splitted_path = malloc(sizeof(char *) * (split_count + 1));
	if (!(process->splitted_path))
	{
		free_array(split);
		return ;
	}
	i = 0;
	while (split[i] && i < split_count)
	{
		process->splitted_path[i] = ft_strjoin(split[i], "/");
		i++;
	}
	process->splitted_path[i] = NULL;
	free_array(split);
}

static char	*get_full_path(t_list *exec)
{
	char	*full_path;
	int		i;

	full_path = NULL;
	i = 0;
	while (exec->envp_array[i])
	{
		if (!ft_strncmp(exec->envp_array[i], "PATH=", 5))
		{
			full_path = ft_strchr(exec->envp_array[i], '=') + 1;
			break ;
		}
		else
			i++;
	}
	return (full_path);
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
		curr = curr->next;
	}
	return (total);
}

void	mallocing_heredoc(t_exc *exc)
{
	exc->process->total_hd = total_heredocs(exc->data->token);
	if (exc->process->total_hd > 0)
	{
		exc->process->limiters = malloc(sizeof(char *) * \
(exc->process->total_hd + 1));
		exc->process->limiters[exc->process->total_hd] = NULL;
	}
}
