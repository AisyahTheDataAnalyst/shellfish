/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:47:24 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:17:32 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_double_array(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
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
		free(node->export_value);
		free(node);
	}
}

// later after doing heredoc, need to free_double_array =**limiters instead
void	freeing(t_exc *exc)
{
	free_double_array(exc->exec->envp_array);
	free_double_array(exc->process->splitted_path);
	free(exc->process->limiters);
	free(exc->process);
	free(exc->exec);
	rl_clear_history();
}
