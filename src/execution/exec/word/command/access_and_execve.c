/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_and_execve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:45:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/26 11:21:47 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		access_and_execve(t_exc *exc, t_ast *ast);
static char	*executable_files(char **args, t_exc *exc);
static char	*access_path(t_exc *exc, char **args);
static int	is_path_var_exist(t_exc *exc);
static void	pathname_error_handling(t_exc *exc, char *pathname, char **args);

void	access_and_execve(t_exc *exc, t_ast *ast)
{
	char	**args;
	char	*pathname;

	args = ast->token->basin_buff;
	reset_signals_tokenword();
	if (!args || !args[0] || !args[0][0])
	{
		free_before_readline(exc);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
	if (!ft_strncmp(args[0], "./", 2))
		pathname = executable_files(args, exc);
	else if (access(args[0], F_OK) != -1)
		pathname = ft_strdup(args[0]);
	else
		pathname = access_path(exc, args);
	pathname_error_handling(exc, pathname, args);
	execve(pathname, args, exc->exec->envp_array);
	free(pathname);
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
		free_before_readline(exc);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
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

	if (!is_path_var_exist(exc))
		return (ft_strdup(args[0]));
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

static int	is_path_var_exist(t_exc *exc)
{
	char	*full_path;
	int		i;

	full_path = "PATH=/home/aimokhta/bin:/home/aimokhta/bin:/usr/local/sbin:\
/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:\
/snap/bin";
	i = 0;
	while (exc->exec->envp_array[i])
	{
		if (!ft_strncmp(exc->exec->envp_array[i], full_path, \
ft_strlen(full_path)))
			break ;
		i++;
	}
	if (!exc->exec->envp_array[i])
		return (0);
	return (1);
}

static void	pathname_error_handling(t_exc *exc, char *pathname, char **args)
{
	if (!pathname || !pathname[0] || access(pathname, F_OK) == -1)
	{
		ft_putstr_fd(args[0], 2);
		ft_putendl_fd(": command not found", 2);
		free(pathname);
		free_before_readline(exc);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
}
