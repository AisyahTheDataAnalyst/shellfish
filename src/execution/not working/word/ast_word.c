/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:22:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ast_word(char **basin_buff, t_exc *exc)
{
	if (is_bi(basin_buff, exc) == 0)
		return(built_ins(basin_buff, exc));
	else
	{
		access_and_execve(exc);
		return (1);
	}
	return (0);
}

void	access_and_execve(t_exc *exc)
{
	char	**args;
	char	*pathname;

	args = exc->token->basin_buff;
	if (!args || !args[0] || !args[0][0])
	{
		free_args(args);
		free_fd_pid_splitted(exc);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp("./", args[0], 2) == 0)
	{
		free_args(args);
		free_fd_pid_splitted(exc);
		exit(EXIT_FAILURE);
	}
	if (access(args[0], F_OK) != -1)
		pathname = args[0];
	else
		pathname = access_path(exc, args);
	pathname_error_handling(pathname, args, exc);
	execve(pathname, args, exc->exec->envp_array);
	free_args(args);
	free_fd_pid_splitted(exc);
	exit(CMD_NOT_FOUND);
}
