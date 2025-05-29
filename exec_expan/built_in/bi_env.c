/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:46:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/28 11:10:38 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(char **envp, t_list *exec)
{
	int	i;

	i = 0;
	if (!exec->envp_array)
		envp_to_envparray(envp, exec);
	while (exec->envp_array[i])
	{
		printf("%s\n", exec->envp_array[i]);
		i++;
	}
}
