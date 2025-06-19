/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:47:24 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 10:29:42 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	free_temp_list(t_list *temp_list)
{
	int		i;
	t_list	*temp;
	t_list	*node;

	i = 0;
	temp = temp_list;
	while (temp)
	{
		node = temp;
		temp = temp->next;
		free(node->export_name);
		free(node);
	}
}

void	freeing(t_list *exec)
{
	free_double_array(exec->envp_array);
	free_double_array(exec->splitted_path);
	free(exec);
	rl_clear_history();
}
