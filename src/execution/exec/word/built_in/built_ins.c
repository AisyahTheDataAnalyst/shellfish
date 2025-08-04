/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:15:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/04 14:36:24 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// builtins - dont use execve coz it need to make actual changes 
// in the current room/process
// if it use execve, execve will bring it to the new room,
// but then come back to the original room remain unchanged
// other than builtins - called external programs (ls, cat, etc)

int	is_bi(char **args)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		return (1);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		return (1);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		return (1);
	return (0);
}

void	exec_builtin(t_ast *ast, t_exc *exc)
{
	dupping_stdin_stdout(exc);
	dup2_close_infile_outfile(exc);
	built_ins(ast->token->basin_buff, exc);
	reset_stdin_stdout(exc);
}

void	built_ins(char **args, t_exc *exc)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		bi_echo(args, exc);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		bi_cd(args, exc);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		bi_pwd(exc);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		bi_export(args, exc);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		bi_env(args, exc);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		bi_unset(args, exc);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		bi_exit(args, exc);
	else
		return ;
}
