/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:40:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/29 09:13:52 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// signal Cntrl+C
void handle_cntrl_c(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// signal Cntrl+D
void handle_cntrl_d(int sig) //, t_list *exec)
{
	(void)sig;
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
