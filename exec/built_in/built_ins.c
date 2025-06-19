/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:15:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/18 09:36:11 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_ins(char **args, t_data *data)
{
	if (!args[0])
		return ;
	else if (ft_strncmp(args[0], "echo", 5) == 0)
		bi_echo(args, data);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		bi_cd(args, data);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		bi_pwd(args, data);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		bi_export(args, data);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		bi_env(data);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		bi_unset(args, data);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		bi_exit(args, data);
	else
		return ;
}
