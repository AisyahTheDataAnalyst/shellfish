/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:22 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/07 14:11:15 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	int_main_init(t_exc *exc, char **envp);
static void	int_main_loop(t_exc *exc);

int	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_exc	*exc;

	(void)av;
	if (ac != 1)
		return (1);
	exc = malloc(sizeof(t_exc));
	int_main_init(exc, envp);
	int_main_loop(exc);
	freeing(exc);
	printf("exit\n");
	return (0);
}

// do signals outside loop, introducing the action for the signals only, 
// 	if put in the loop, it will be redundant, resetting ion every loop
// 	if later you change it overwrite with another signal fn, you reset it, bug.
//
// ascii 4 = EOT = end of transmission = Cntrl D = EOF
// ascii 3 = ETX = end of text = Cntrl C = SIGINT
// ascii 28 = FS = file separator / QUIT = Cntrl backslash = SIGQUIT
// SIG_IGN = signal ignore = for cntrl backslash
static void	int_main_init(t_exc *exc, char **envp)
{
	ft_bzero(exc, sizeof(t_exc));
	exc->exec = malloc(sizeof(t_list));
	ft_bzero(exc->exec, sizeof(t_list));
	exc->process = malloc(sizeof(t_process));
	ft_bzero(exc->process, sizeof(t_process));
	exc->process->limiters = malloc(sizeof(char *) * \
(total_heredocs(exc->token) + 1));
	exc->process->infile = -1;
	exc->process->outfile = -1;
	get_splitted_path(exc->process);
	envp_to_envparray(envp, exc->exec);
	reset_signals();
}

// only add_history if theres not an empty readline
static void	int_main_loop(t_exc *exc)
{
	char	*input;
	char	**basin;

	while (1)
	{
		input = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
		if (!input)
		{
			free(input);
			break ;
		}
		basin = ft_split(input, ' ');
		// ast_execution(exc, exc->process);
		built_ins(basin, exc);
		if (ft_strncmp(input, "\n", 2) > 0)
			add_history(input);
		reset_g_signal_code(exc);
		free_double_array(basin);
		free(input);
	}
}
