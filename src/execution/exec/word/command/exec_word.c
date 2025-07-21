/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:07:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/21 17:07:25 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		exec_word(t_ast *ast, t_exc *exc);
static void	access_and_execve(t_exc *exc, t_ast *ast);
static char	*access_path(t_exc *exc, char **args);
static void	pathname_error_handling(t_exc *exc, char *pathname, char **args);
static void	waiting_exec_word(pid_t pid, int exit_status, t_exc *exc);

void	exec_word(t_ast *ast, t_exc *exc)
{
	pid_t	pid;
	int		exit_status;

	exit_status = 0;
	if (is_bi(ast->token->basin_buff) == 1)
		exec_builtin(ast, exc);
	else
	{
		signal(SIGINT, SIG_IGN);
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
		waiting_exec_word(pid, exit_status, exc);
		reset_stdin_stdout_unlink_heredocfd(exc);
	}
}

static void	access_and_execve(t_exc *exc, t_ast *ast)
{
	char	**args;
	char	*pathname;

	args = ast->token->basin_buff;
	reset_signals_child();
	if (!args || !args[0] || !args[0][0])
	{
		free_before_readline(exc);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
	if (access(args[0], F_OK) != -1)
		pathname = ft_strdup(args[0]);
	else
		pathname = access_path(exc, args);
	pathname_error_handling(exc, pathname, args);
	execve(pathname, args, exc->exec->envp_array);
	free_before_readline(exc);
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
		ft_putstr_fd("shellfish: command not found: ", 2);
		ft_putendl_fd(args[0], 2);
		free_before_readline(exc);
		free(pathname);
		exc->exit_code = CMD_NOT_FOUND;
		exit(exc->exit_code);
	}
}

// WIFEXITED(status) 
//	= returns true - child exited normally: using exit() / return from main()
// WIFEXITED(status) 
//	= returns false - child killed by signal (SIGINT / SIGSEGV)
// WEXITSTATUS (used only when WIFEXITED(status) is true) 
//	= the exit code the child returned 
// WIFSIGNALED(status) 
//	= returns true - child killed by smthg (SIGINT / kill() / SIGSEGV)
// WTERMSIG(status) (used only if WIFSIGNALED(status) is true) 
//	= what signal killed the child 
// ( == 0) ---> false
// ( != 0) ---> true
// we need WIFSIGNALED coz we dont have signal_handler function (SIG_DFL)
static void	waiting_exec_word(pid_t pid, int exit_status, t_exc *exc)
{
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status) != 0)
		exc->exit_code = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status) != 0)
	{
		exc->exit_code = 128 + WTERMSIG(exit_status);
		if (WTERMSIG(exit_status) == SIGINT)
			write(1, "\n", 1);
	}
}
