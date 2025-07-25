/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:54:37 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/25 12:35:30 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	signals_for_heredoc(void)
{
	signal(SIGINT, handle_cntrl_c_heredoc);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d_heredoc);
}

void	reset_signals(void)
{
	signal(SIGINT, handle_cntrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d);
}

void	reset_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, SIG_DFL);
}

void	reset_before_readline(t_exc *exc)
{
	if (g_signal != 0)
	{
		exc->exit_code = g_signal;
		g_signal = 0;
	}
	reset_signals();
	if (exc->process->total_hd > 0)
		exc->process->limiter_index = 0;
	exc->process->infile = -1;
	exc->process->outfile = -1;
	exc->process->heredoc_fd = -1;
	exc->process->pipe_flag = false;
	exc->process->reset_cursor_hd = false;
	if (access("heredoc_fd", F_OK) == 0)
		unlink("heredoc_fd");
}
