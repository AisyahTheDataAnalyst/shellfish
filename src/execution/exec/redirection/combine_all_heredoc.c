/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_all_heredoc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:00:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/24 16:51:37 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		combine_all_heredoc(t_ast *ast, t_exc *exc);
static void	heredoc_process(t_exc *exc);
static void	start_heredoc(t_exc *exc);
static char	*multiple_heredocs(char *final_limiter, char *line, \
int total_hd, t_process *process);
static bool	is_limiter(char *limiter, char *line);

void	combine_all_heredoc(t_ast *ast, t_exc *exc)
{
	if (!ast)
		return ;
	if (ast->token->token_type == TOKEN_HEREDOC)
	{
		exc->process->limiters[exc->process->limiter_index] = \
ft_strdup(ast->token->basin_buff[0]);
		exc->process->limiter_index++;
		if (exc->process->limiter_index == exc->process->total_hd)
			heredoc_process(exc);
	}
	combine_all_heredoc(ast->left, exc);
	combine_all_heredoc(ast->right, exc);
}

static void	heredoc_process(t_exc *exc)
{
	pid_t	pid;
	int		exit_status;

	exc->process->heredoc_fd = open("heredoc_fd", \
O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (exc->process->heredoc_fd == -1)
	{
		ft_putendl_fd("shellfish: heredoc_fd: Permission denied", 2);
		exc->exit_code = PERMISSION_DENIED;
		return ;
	}
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		perror("Heredoc's fork failed");
	if (pid == 0)
		start_heredoc(exc);
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status) != 0)
		exc->exit_code = WEXITSTATUS(exit_status);
	close(exc->process->heredoc_fd);
	exc->process->heredoc_fd = reset_cursor_heredocfd(exc);
	exc->process->infile = exc->process->heredoc_fd;
}

static void	start_heredoc(t_exc *exc)
{
	char	*final_limiter;
	char	*line;

	signals_for_heredoc();
	line = readline("\033[0;34m> \033[0m");
	final_limiter = exc->process->limiters[exc->process->total_hd - 1];
	if (exc->process->total_hd > 1)
		line = multiple_heredocs(final_limiter, line, \
exc->process->total_hd, exc->process);
	while (line && is_limiter(final_limiter, line) == false)
	{
		write(exc->process->heredoc_fd, line, ft_strlen(line));
		write(exc->process->heredoc_fd, "\n", 1);
		// fprintf(stderr, "writing user input of heredoc\n");
		free(line);
		line = readline("\033[0;34m> \033[0m");
	}
	free(line);
	close(exc->process->heredoc_fd);
	free_before_readline(exc);
	exc->exit_code = EXIT_SUCCESS;
	exit(exc->exit_code);
}

static char	*multiple_heredocs(char *final_limiter, char *line, \
int total_hd, t_process *process)
{
	bool	curr_limiter;

	process->limiter_index = 0;
	while (process->limiter_index < total_hd)
	{
		if (process->limiters[process->limiter_index] == final_limiter)
			break ;
		curr_limiter = is_limiter(process->limiters[process->limiter_index], \
line);
		if (curr_limiter == true)
			process->limiter_index++;
		free(line);
		line = readline("\033[0;34m> \033[0m");
	}
	return (line);
}

static bool	is_limiter(char *limiter, char *line)
{
	size_t	len;

	len = ft_strlen(limiter);
	if (!limiter || !line)
		return (false);
	if (ft_strncmp(limiter, line, len) == 0)
		if (line[len] == '\0')
			return (true);
	return (false);
}
