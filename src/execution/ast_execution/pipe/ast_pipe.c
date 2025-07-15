/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:40:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/15 12:36:23 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		ast_pipe(t_ast *ast, t_exc *exc);
static void	child_process_left(t_ast *ast, t_exc *exc, int fd[2]);
static void	child_process_right(t_ast *ast, t_exc *exc, int fd[2]);
static void	parent_process(t_exc *exc, int fd[2], pid_t left_pid, \
pid_t right_pid);

// when passing the fd[2] to another function as a parameter,
// should pass the whole array, not just a single element
// this will pass int fd[2] array as a pointer
void	ast_pipe(t_ast *ast, t_exc *exc)
{
	int		fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	exc->process->pipe_flag = true;
	if (pipe(fd) == -1)
	{
		perror("Pipe failed to open\n");
		return ;
	}
	left_pid = fork();
	if (left_pid < 0)
		perror("Fork failed\n");
	else if (left_pid == 0)
		child_process_left(ast, exc, fd);
	right_pid = fork();
	if (left_pid < 0)
		perror("Fork failed\n");
	else if (right_pid == 0)
		child_process_right(ast, exc, fd);
	parent_process(exc, fd, left_pid, right_pid);
}

//put exit(0) at the end in case its a builtin or ast's NULL
static void	child_process_left(t_ast *ast, t_exc *exc, int fd[2])
{
	reset_signals();
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
	ast_execution(ast->left, exc);
	exit(exc->exit_code);
}

//put exit(0) at the end in case its a builtin or ast's NULL
// only pipe has the power to do ast->right
static void	child_process_right(t_ast *ast, t_exc *exc, int fd[2])
{
	reset_signals();
	close(fd[WRITE]);
	dup2(fd[READ], STDIN_FILENO);
	close(fd[READ]);
	ast_execution(ast->right, exc);
	exit(exc->exit_code);
}

static void	parent_process(t_exc *exc, int fd[2], pid_t left_pid, \
pid_t right_pid)
{
	int		exit_status;

	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(left_pid, &exit_status, 0);
	waitpid(right_pid, &exit_status, 0);
	if (WIFEXITED(exit_status) != 0)
		exc->exit_code = WEXITSTATUS(exit_status);
}
