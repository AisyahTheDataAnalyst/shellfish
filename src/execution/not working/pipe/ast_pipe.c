/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:40:12 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ast_pipe(t_exc *exc)
{
	int		fd[2];
	pid_t	left_pid;
	pid_t	right_pid;
	pid_t	last_pid;

	if (pipe(fd) == -1)
		perror("Pipe failed to open\n");
	left_pid = fork();
	if (left_pid < 0)
		perror("Fork failed\n");
	else if (left_pid == 0)
		child_process_left(exc, fd[2]);
	right_pid = fork();
	if (left_pid < 0)
		perror("Fork failed\n");
	else if (right_pid == 0)
		child_process_right(exc, fd[2]);
	parent_process(exc, fd[2], left_pid, right_pid);
}

static void	child_process_left(t_exc *exc, int fd[2])
{
	signal(SIGINT, handle_cntrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d);
	close(fd[READ]);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
	ast_execution(exc->ast->left);
	exit(0);
}

static void	child_process_right(t_exc *exc, int fd[2])
{
	signal(SIGINT, handle_cntrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d);
	close(fd[WRITE]);
	dup2(fd[READ], STDIN_FILENO);
	close(fd[READ]);
	ast_execution(exc->ast->right);
	exit(0);
}

static void	parent_process(t_exc *exc, int fd[2], pid_t left_pid, pid_t right_pid)
{
	int		new_exit_code;
	int		exit_status;
	pid_t	last_pid;

	exc->last_pid = right_pid;
	close(fd[READ]);
	close(fd[WRITE]);
	waitpid(left_pid, &exit_status, NULL);
	waitpid(right_pid, &exit_status, NULL);
	if (WIFEXITED(exit_status) != 0)
	{
		new_exit_code = WEXITSTATUS(exit_status);
		g_signal = new_exit_code;
	}
}
