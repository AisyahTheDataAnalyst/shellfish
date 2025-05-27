/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:46:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:26:22 by aimokhta         ###   ########.fr       */
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
	printf("testing env_array\n");
	// else
	// {
	// 	while (envp[i])
	// 	{
	// 		printf("%s\n", envp[i]);
	// 		i++;
	// 	}
	// 	printf("testing env_ori\n");
	// }
}
