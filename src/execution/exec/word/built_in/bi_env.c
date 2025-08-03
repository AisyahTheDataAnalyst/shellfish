/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:46:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/30 13:27:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	bi_env(char **av, t_exc *exc)
{
	int	i;

	if (av[1])
	{
		ft_putstr_fd("env: \'", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd("\': No such file or directory", 2);
		exc->exit_code = CMD_NOT_FOUND;
		return ;
	}
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
