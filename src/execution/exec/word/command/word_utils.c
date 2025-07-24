/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:33:21 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/24 11:47:37 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	dupping_stdin_stdout(t_exc *exc)
{
	exc->process->dupped_stdout = dup(STDOUT_FILENO);
	exc->process->dupped_stdin = dup(STDIN_FILENO);
}

void	dup2_close_infile_outfile(t_exc *exc)
{
	if (exc->process->infile != -1)
	{
		dup2(exc->process->infile, STDIN_FILENO);
		close(exc->process->infile);
		if (exc->process->heredoc_fd != -1 && \
exc->process->infile != exc->process->heredoc_fd)
			close(exc->process->heredoc_fd);
	}
	if (exc->process->outfile != -1)
	{
		dup2(exc->process->outfile, STDOUT_FILENO);
		close(exc->process->outfile);
	}
}

void	close_infile_outfile_parent(t_exc *exc)
{
	if (exc->process->infile != -1)
	{
		close(exc->process->infile);
		if (exc->process->heredoc_fd != -1 && \
exc->process->infile != exc->process->heredoc_fd)
			close(exc->process->heredoc_fd);
	}
	if (exc->process->outfile != -1)
		close(exc->process->outfile);
}

void	reset_stdin_stdout_unlink_heredocfd(t_exc *exc)
{
	dup2(exc->process->dupped_stdin, STDIN_FILENO);
	close(exc->process->dupped_stdin);
	dup2(exc->process->dupped_stdout, STDOUT_FILENO);
	close(exc->process->dupped_stdout);
	if (access("heredoc_fd", F_OK) == 0)
		unlink("heredoc_fd");
}


