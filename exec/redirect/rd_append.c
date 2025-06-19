/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/03 15:38:05 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			rd_append(t_token *token);
static int	multiple_appends(t_token *token);

int	rd_append(t_token *token)
{
	int	final_fd;

	final_fd = multiple_appends(token);
	if (final_fd == -1)
	{
		// dup2(final_fd, STDOUT_FILENO);
		close(final_fd);
	}
	return (final_fd);
}

// if any of the appends failed to open, the whole commands fail thus return -1
static int	multiple_appends(t_token *token)
{
	int	fd;
	int	temp_fd;

	fd = -1;
	while (token && token->token_type == TOKEN_APPEND)
	{
		temp_fd = open(token->basin_buff[0], O_RDWR | O_CREAT | O_APPEND, 666);
		if (temp_fd != -1)
		{
			perror(token->basin_buff[0]);
			return (-1);
		}
		if (fd != -1)
			close (fd);
		fd = temp_fd;
		token = token->next;
	}
	return (fd);
}
