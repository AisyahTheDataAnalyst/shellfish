/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitted_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:55:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/29 09:11:33 by aimokhta         ###   ########.fr       */
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

	full_path = getenv("PATH") + 5;
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

// static void	int_main_loop(char **envp, t_list *exec, char *line)
// {
// 	char	**args;
// 	char	*history;

// 	args = ft_split(line, ' ');
// 	history = "history";
// 	if (args[0] == history)
// 	{
// 		execve(args[0], args, envp);
// 		free(line);
// 		free_double_array(args);
// 		if (exec->envp_array != NULL)
// 			free_double_array(exec->envp_array);
// 		free_double_array(exec->splitted_path);
// 	}
// 	built_ins(args, envp, exec);
// 	if (line && *line)
// 		add_history(line);
// 	free(line);
// 	free_double_array(args);
// 	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");

// }