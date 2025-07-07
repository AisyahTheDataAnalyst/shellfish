/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:16:04 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	rd_append(t_exc *exc);
int	rd_in(t_exc *exc);
int	rd_out(t_exc *exc);

int	rd_append(t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(exc->token->basin_buff[0], O_RDWR | O_CREAT | O_APPEND, 666);
	if (temp_fd == -1)
	{
		perror("Failed to open file for append");
		return (0);
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	dup2(exc->process->outfile, STDOUT_FILENO);
	close(exc->process->outfile);
	return (ast_execution(exc->ast->left));
}

int	rd_in(t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(exc->token->basin_buff[0], O_RDONLY);
	if (temp_fd == -1)
	{
		perror("Failed to open file for redirection in");
		return (0);
	}
	if (exc->process->infile != -1)
		close(exc->process->infile);
	exc->process->infile = temp_fd;
	dup2(exc->process->infile, STDIN_FILENO);
	close(exc->process->infile);
	return (ast_execution(exc->ast->left));
}

int	rd_out(t_exc *exc)
{
	int	temp_fd;

	temp_fd = open(exc->token->basin_buff[0], O_RDWR | O_CREAT | O_TRUNC, 666);
	if (temp_fd == -1)
	{
		perror("Failed to open file for redirection out");
		return (0);
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
	exc->process->outfile = temp_fd;
	dup2(exc->process->outfile, STDOUT_FILENO);
	close(exc->process->outfile);
	return (ast_execution(exc->ast->left));
}



