/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:00:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	rd_heredoc(t_exc *exc)
{
	char	*line;
	int		fd_in[2];
	t_ast	*temp;

	temp = exc->ast;
	exc->process->limiters[exc->process->limiter_index] = \
ft_strdup(exc->token->basin_buff[0]);
	exc->process->limiter_index++;
	while (temp->token->token_type != TOKEN_WORD)
		temp->left = temp;
	while (temp->token->token_type != TOKEN_HEREDOC)
		temp->left = temp;
	if (exc->ast->token == temp)
		if (!start_heredoc(exc))
			return (0);
	return (ast_execution(exc->ast->left));
}

int	start_heredoc(t_exc *exc)
{
	char	*line;
	int		fd_in[2];
	char	*final_limiter;
	int		total_hd;

	if (pipe(fd_in) == -1)
		return (0);
	line = readline("\033[0;34m> $\033[0m");
	total_hd = total_heredocs(exc->token);
	final_limiter = exc->process->limiters[total_heredocs(total_hd) - 1];
	signals_for_heredoc();
	line = multiple_heredocs(final_limiter, line, exc, total_hd);
	line = saving_heredoc_input(final_limiter, line, fd_in[2]);
	free(line);
	dup2(fd_in[WRITE], STDOUT_FILENO);
	close(fd_in[WRITE]);
	reset_signals();
	dup2(fd_in[READ], STDIN_FILENO);
	close(fd_in[READ]);
	return (1);
}

char	*saving_heredoc_input(char *final_limiter, char *line, int fd_in[2])
{
	while (1)
	{
		if (is_limiter(final_limiter, line))
			break ;
		write(fd_in[WRITE], line, ft_strlen(line));
		free(line);
		line = readline("\033[0;34m> $\033[0m");
	}
	return (line);
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
		curr_limiter = is_limiter(process->limiters[process->limiter_index], line);
		if (curr_limiter == true)
			process->limiter_index++;
		free(line);
		write(STDOUT_FILENO, "> ", ft_strlen("> "));
		line = get_next_line(STDIN_FILENO);
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
		if (line[len] == '\n')
			return (true);
	return (false);
}
