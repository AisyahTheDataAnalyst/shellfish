/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:47:24 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/26 15:32:31 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_array(char **s)
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
	t_list	*temp;
	t_list	*node;

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

// later after doing heredoc, need to free_array =**limiters instead
void	freeing(t_exc *exc)
{
	free_array(exc->exec->envp_array);
	free(exc->process);
	free(exc->exec);
	rl_clear_history();
}

void	free_before_readline(t_exc *exc)
{
	if (exc->data->token)
		free_token_list(exc->data);
	if (exc->data->root)
		free_ast(exc->data);
	if (exc->process->splitted_path)
		free_array(exc->process->splitted_path);
	if (exc->process->total_hd > 0)
		free_array(exc->process->limiters);
}
