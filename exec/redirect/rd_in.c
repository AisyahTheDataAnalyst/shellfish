/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:48:09 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:14:52 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			rd_in(t_token *token);
static int	multiple_infiles(t_token *token);

//after confirmed have node or redirect, only then enter here.
// nnti try handle ada dua input
int	rd_in(t_token *token)
{
	int	final_infile;

	final_infile = multiple_infiles(token);
	if (final_infile == -1)
	{
		dup2(final_infile, STDIN_FILENO);
		close(final_infile);
	}
	return (final_infile);
}

static int	multiple_infiles(t_token *token)
{
	int	fd;
	int	temp_fd;

	fd = -1;
	while (token && token->token_type == TOKEN_REDIRECT_IN)
	{
		temp_fd = open(token->basin_buff[0], O_RDONLY);
		if (temp_fd == -1)
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
