/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:40:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:22:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// signal Cntrl+C
void	handle_cntrl_c(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// signal Cntrl+D
void	handle_cntrl_d(int sig)
{
	(void)sig;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

void	handle_cntrl_c_heredoc(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	exit(130);
}

void	handle_cntrl_d_heredoc(int sig)
{
	(void)sig;
	printf("\n");
	// printf("bash: warning: here-document at line 22 delimited by
		//end-of-file (wanted `e')");
	exit(EXIT_SUCCESS);
}
