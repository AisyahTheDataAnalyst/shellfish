/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_and_execve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:45:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/24 17:14:24 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		access_and_execve(t_exc *exc, t_ast *ast);
static void	exit_access_and_execve(t_exc *exc);
static char	*executable_files(char **args, t_exc *exc);
static char	*access_path(t_exc *exc, char **args);
static void	pathname_error_handling(t_exc *exc, char *pathname, char **args);

void	access_and_execve(t_exc *exc, t_ast *ast)
{
	char	**args;
	char	*pathname;

	args = ast->token->basin_buff;
	reset_signals_child();
	// fprintf(stderr, "%s\n", args[0]);
	if (!args || !args[0] || !args[0][0])
		exit_access_and_execve(exc);
	if (!ft_strncmp(args[0], "./", 2))
		pathname = executable_files(args, exc);
	else if (access(args[0], F_OK) != -1)
		pathname = ft_strdup(args[0]);
	else
		pathname = access_path(exc, args);
	pathname_error_handling(exc, pathname, args);
	// fprintf(stderr, "exit_code current in access_execeve betul22222 b4 execve = %d with command: %s\n", exc->exit_code, ast->token->basin_buff[0]);
	execve(pathname, args, exc->exec->envp_array);
	free(pathname);
	fprintf(stderr, "exit_code current in access_execveafter execve after exit = %d with command: %s\n", exc->exit_code, ast->token->basin_buff[0]);
	exit_access_and_execve(exc);
}

static void	exit_access_and_execve(t_exc *exc)
{
	free_before_readline(exc);
	exc->exit_code = CMD_NOT_FOUND;
	exit(exc->exit_code);
}

static char	*executable_files(char **args, t_exc *exc)
{
	char	*pathname;

	pathname = NULL;
	if (!access(args[0], F_OK) && !access(args[0], X_OK))
		pathname = ft_strdup(args[0]);
	else
	{
		ft_putstr_fd("shellfish: ", 2);
		perror(args[0]);
		exit_access_and_execve(exc);
	}
	return (pathname);
}

///usr/bin is a directory
// that stores many executable programs (binaries) like ls/cat/grep/etc
//
// /usr/bin/ls is a binary executable file
// we join them to fund where is the executable ls is stored
// when you run ls, you are running the program located at /usr/bin/ls
//
// access - to see if the normal file (/usr/bin/ls) exists 
// a.k.a. executable binary file
static char	*access_path(t_exc *exc, char **args)
{
	int		i;
	char	*pathname;

	i = 0;
	while (exc->process->splitted_path[i])
	{
		pathname = ft_strjoin(exc->process->splitted_path[i], args[0]);
		if (access(pathname, F_OK) == 0)
			return (pathname);
		else
		{
			free(pathname);
			i++;
		}
	}
	return (NULL);
}

static void	pathname_error_handling(t_exc *exc, char *pathname, char **args)
{
	if (!pathname || !pathname[0])
	{
		ft_putstr_fd(args[0], 2);
		ft_putendl_fd(": command not found", 2);
		free(pathname);
		exit_access_and_execve(exc);
	}
}
