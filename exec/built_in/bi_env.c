/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:46:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/15 15:51:26 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	bi_env(char **envp, t_list *exec)
void	bi_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->exec->envp_array[i])
	{
		printf("%s\n", data->exec->envp_array[i]);
		i++;
	}
	data->exit_code = 0;
}
