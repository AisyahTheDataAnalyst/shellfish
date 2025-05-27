/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:15:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/26 15:26:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_ins(char **args, char **envp, t_list *exec)
{
	if (!args[0])
		return ;
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		bi_echo(args);
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		bi_cd(args, envp, exec);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		bi_pwd(args);
	else if (ft_strncmp(args[0], "export", 6) == 0)
		bi_export(args, envp, exec);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		bi_env(envp, exec);
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		bi_unset(args, envp, exec);
	else if (ft_strncmp(args[0], "exit", 4) == 0)
		bi_exit(args, exec);
	else
		return ;
}
