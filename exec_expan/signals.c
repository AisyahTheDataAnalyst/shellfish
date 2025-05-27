/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:40:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:36:12 by aimokhta         ###   ########.fr       */
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

// signal Cntrl back slash
// void handle_cntrl_backslash(int sig)
// {
// 	(void)sig;
// 	return ;
// 	// rl_on_new_line();
// 	// rl_redisplay();
// 	// rl_replace_line("", 0);
// }

// signal Cntrl+D
void handle_cntrl_d(int sig) //, t_list *exec)
{
	(void)sig;
	// if (exec->envp_array != NULL)
	// 	free_double_array(exec->envp_array);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
