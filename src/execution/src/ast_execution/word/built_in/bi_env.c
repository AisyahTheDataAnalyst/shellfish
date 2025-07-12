/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:46:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:04 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// void	bi_env(char **envp, t_list *exec)
void	bi_env(t_exc *exc)
{
	int	i;

	i = -1;
	while (exc->exec->envp_array[++i])
	{
		if (!ft_strchr(exc->exec->envp_array[i], '='))
			continue ;
		else
			printf("%s\n", exc->exec->envp_array[i]);
	}
	exc->exit_code = 0;
}
