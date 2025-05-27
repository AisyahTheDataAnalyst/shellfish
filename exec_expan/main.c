/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:22 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:35:38 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	int_main_init(t_list *exec);
static char	*int_main_loop(char **envp, t_list *exec, char *line);

// char *prompt_ptr = ft_strjoin("\033[0;32mminishell $\033[0m ",
// getcwd(NULL, 0));
// line = readline(prompt_ptr);
// add_history = so can do arrow up for looking history
// 
int	main(int ac, char **av, char **envp)
{
	t_list	exec;
	char	*line;

	(void)ac;
	(void)av;
	int_main_init(&exec);
	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
	if (!line)
		freeing(&exec);
	while (line)
		line = int_main_loop(envp, &exec, line);
	freeing(&exec);
	return (0);
}

// full_path = get_full_path(envp);
// get_splitted_path(exec, full_path);
//
// do signals outside loop, introducing the action for the signals only, 
// 	if put in the loop, it will be redundant, resetting ion every loop
// 	if later you change it overwrite with another signal fn, you reset it, bug.
//
// ascii 4 = EOT = end of transmission = Cntrl D = EOF
// ascii 3 = ETX = end of text = Cntrl C = SIGINT
// ascii 28 = FS = file separator / QUIT = Cntrl backslash = SIGQUIT
// SIG_IGN = signal ignore = for cntrl backslash
static void	int_main_init(t_list *exec)
{
	ft_bzero(exec, sizeof(t_list));
	get_splitted_path(exec);
	signal(SIGINT, handle_cntrl_c);
	signal(SIGQUIT, SIG_IGN);
	// if (signal(EOF, handle_cntrl_d))
	// {
	// 	freeing(exec);
	// 	// exit(EXIT_FAILURE);
	// }
}

// line = (user press enter only)
// *line = "" (checking within the string of its empty, line[][])
static char	*int_main_loop(char **envp, t_list *exec, char *line)
{
	char	**args;

	args = ft_split(line, ' ');
	built_ins(args, envp, exec);
	if (line && *line)
		add_history(line);
	free(line);
	free_double_array(args);
	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
	if (!line)
		freeing(exec);
	return (line);
}
