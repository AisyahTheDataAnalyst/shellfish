/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset_ori.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:12:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:29:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void		unset_ori(char **av, char **envp, t_list *exec);
// static char	**unset_ori_marking(char **av, char **envp);
// int			mark_count(char **temp);
// static char	**unset_ori_marking_helper(char **av, char **envp, char **temp);

// void	unset_ori(char **av, char **envp, t_list *exec)
// {
// 	char	**temp;
// 	int		i;
// 	int		j;
// 	int		count;

// 	temp = NULL;
// 	temp = unset_ori_marking(av, envp);
// 	count = mark_count(temp);
// 	if (exec->envp_array)
// 		free_double_array(exec->envp_array);
// 	exec->envp_array = malloc(sizeof(char *) * (count + 1));
// 	if (!exec->envp_array)
// 		return ;
// 	i = 0;
// 	j = 0;
// 	while (temp[i])
// 	{
// 		if (ft_strncmp("!", temp[i], 1) != 0)
// 			exec->envp_array[j++] = ft_strdup(temp[i]);
// 		i++;
// 		printf("testing unset_ori\n");
// 	}
// 	exec->envp_array[j] = NULL;
// 	free_double_array(temp);
// }

// static char	**unset_ori_marking(char **av, char **envp)
// {
// 	int		i;
// 	char	**temp;

// 	i = ft_array_size(envp);
// 	temp = malloc(sizeof(char *) * (i + 1));
// 	if (!temp)
// 		return (NULL);
// 	temp = unset_ori_marking_helper(av, envp, temp);
// 	return (temp);
// }

// static char	**unset_ori_marking_helper(char **av, char **envp, char **temp)
// {
// 	int		i;
// 	int		j;
// 	bool	match;

// 	i = -1;
// 	while (envp[++i])
// 	{
// 		match = false;
// 		j = 1;
// 		while (av[j])
// 		{
// 			if (ft_strncmp(envp[i], av[j], ft_strlen(av[j])) == 0
// 				&& envp[i][ft_strlen(av[j++])] == '=')
// 			{
// 				match = true;
// 				break ;
// 			}
// 		}
// 		if (match == true)
// 			temp[i] = ft_strjoin("!", envp[i]);
// 		else
// 			temp[i] = ft_strdup(envp[i]);
// 	}
// 	temp[i] = NULL;
// 	return (temp);
// }
