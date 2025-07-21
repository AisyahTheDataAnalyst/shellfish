/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:40:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/21 11:34:33 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// write newline -> to print out every ^C for every new prompt
// rl_on_new_line() -> to create the next prompt onto the next newline
// rl_replace_line("", 0) -> to empty the next prompt
// rl_redisplay() -> to display next prompt instantly waiting for input
// signal Cntrl+C
void	handle_cntrl_c(int sig)
{
	if (sig == SIGINT)
	{
		g_signal = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// signal Cntrl+D (EOF)
// when in env -i, exit isnt on newline -- same with bash, so its good.
void	handle_cntrl_d(int sig)
{
	(void)sig;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

void	handle_cntrl_c_heredoc(int sig)
{
	if (sig == SIGINT)
		g_signal = 130;
	write(STDOUT_FILENO, "\n", 1);
	exit(g_signal);
}

void	handle_cntrl_d_heredoc(int sig)
{
	(void)sig;
	printf("\n");
	g_signal = EXIT_SUCCESS;
	exit(g_signal);
}
