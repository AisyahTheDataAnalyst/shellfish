/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:00:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:18:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			rd_heredoc(t_token *token);
static char	*last_limiter(t_token *token);
static char	*multiple_heredocs(char *final_limiter, char *line, t_token *token);
static int	is_limiter(char *limiter, char *line);

int	rd_heredoc(t_token *token)
{
	char	*line;
	int		fd_in[2];
	char	*final_limiter;

	if (pipe(fd_in) == -1)
		return (-1);
	line = readline("\033[0;34m> $\033[0m");
	final_limiter = last_limiter(token);
	signal(SIGINT, handle_cntrl_c_heredoc);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d_heredoc);
	line = multiple_heredocs(final_limiter, line, token);
	while (1)
	{
		if (is_limiter(final_limiter, line))
			break ;
		write(fd_in[WRITE], line, ft_strlen(line));
		free(line);
		line = readline("\033[0;34m> $\033[0m");
	}
	free(line);
	close(fd_in[WRITE]);
	signal(SIGINT, handle_cntrl_c);
	signal(EOF, handle_cntrl_d);
	return (fd_in[READ]);
}

static char	*last_limiter(t_token *token)
{
	char	*final_limiter;

	while (token && token->token_type == TOKEN_HEREDOC)
	{
		final_limiter = token->basin_buff[0];
		token = token->next;
	}
	return (final_limiter);
}

// static char	*last_limiter(t_token *token)
// {
// 	int		i;

// 	i = 0;
// 	while (token->basin_buff[i + 1])
// 		i++;
// 	return (token->basin_buff[i]);
// }

static char	*multiple_heredocs(char *final_limiter, char *line, t_token *token)
{
	int	curr_limiter;

	while (token && token->token_type == TOKEN_HEREDOC)
	{
		if (token->basin_buff[0] == final_limiter)
			break ;
		curr_limiter = is_limiter(token->basin_buff[0], line);
		if (curr_limiter)
			token = token->next;
		free(line);
		write(STDOUT_FILENO, "> ", ft_strlen("> "));
		line = get_next_line(STDIN_FILENO);
	}
	return (line);
}

static int	is_limiter(char *limiter, char *line)
{
	size_t	len;

	len = ft_strlen(limiter);
	if (!limiter || !line)
		return (0);
	if (ft_strncmp(limiter, line, len) == 0)
		if (line[len] == '\n')
			return (1);
	return (0);
}
