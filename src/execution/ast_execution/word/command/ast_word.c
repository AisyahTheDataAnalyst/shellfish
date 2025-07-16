/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:22:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/16 09:19:10 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		ast_word(t_ast *ast, t_exc *exc);
static void	access_and_execve(t_exc *exc, t_ast *ast);
static char	*access_path(t_exc *exc, char **args);
static void	pathname_error_handling(t_exc *exc, char *pathname, char **args);

void	ast_word(t_ast *ast, t_exc *exc)
{
	pid_t	pid;
	int		exit_status;

	if (is_bi(ast->token->basin_buff) == 1)
		ast_builtin(ast, exc);
	else
	{
		pid = fork();
		dupping_stdin_stdout(exc);
		if (pid < 0)
		{
			perror("Fork for TOKEN_WORD failed");
			return ;
		}
		if (pid == 0)
		{
			dup2_close_infile_outfile(exc);
			access_and_execve(exc, ast);
		}
		close_infile_outfile_parent(exc);
		waitpid(pid, &exit_status, 0);
		if (WIFEXITED(exit_status) != 0)
			exc->exit_code = WEXITSTATUS(exit_status);
		reset_stdin_stdout_unlink_heredocfd(exc);
	}
}

static void	access_and_execve(t_exc *exc, t_ast *ast)
{
	char	**args;
	char	*pathname;

	reset_signals();
	args = ast->token->basin_buff;
	if (!args || !args[0] || !args[0][0])
	{
		free_array(args);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
	if (access(args[0], F_OK) != -1)
		pathname = args[0];
	else
		pathname = access_path(exc, args);
	pathname_error_handling(exc, pathname, args);
	execve(pathname, args, exc->exec->envp_array);
	perror(pathname);
	free_array(args);
	free(pathname);
	exc->exit_code = CMD_NOT_FOUND;
	exit(exc->exit_code);
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
		printf("%s: command not found\n", args[0]);
		free_array(args);
		free(pathname);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
}
