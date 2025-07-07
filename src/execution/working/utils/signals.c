/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:40:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:16:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// signal Cntrl+C
void	handle_cntrl_c(int sig)
{
	if (sig == SIGINT)
		g_signal = 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// signal Cntrl+D
// when in env -i, exit isnt on newline ???
void	handle_cntrl_d(int sig)
{
	(void)sig;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

//how to update this exit_code? using waitpid later okay in the child
void	handle_cntrl_c_heredoc(int sig)
{
	if (sig == SIGINT)
		g_signal = 130;
	write(STDOUT_FILENO, "\n", 1);
	exit(130);
}

void	handle_cntrl_d_heredoc(int sig)
{
	(void)sig;
	printf("\n");
	exit(EXIT_SUCCESS);
}
