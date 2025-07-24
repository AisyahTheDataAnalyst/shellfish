/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:07:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/24 13:45:31 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		exec_word(t_ast *ast, t_exc *exc);
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
		reset_stdin_stdout(exc);
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
