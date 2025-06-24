/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:48:22 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/22 10:43:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	int_main_init(t_data *data, char **envp);
static int	int_main_loop(t_data *data);
// static char	*int_main_loop(t_data *data, char *line);

int	g_signal = 0;

// char *prompt_ptr = ft_strjoin("\033[0;32mminishell $\033[0m ",
// getcwd(NULL, 0));
// line = readline(prompt_ptr);
// add_history = so can do arrow up for looking history
// 
// int	main(int ac, char **av, char **envp)
// {
// 	t_data	data;
// 	char	*line;

// 	(void)av;
// 	if (ac != 1)
// 		return (1);
// 	int_main_init(&data, envp);
// 	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
// 	if (!line)
// 		freeing(data.exec);
// 	while (line)
// 		line = int_main_loop(&data, line);
// 	free(line);
// 	freeing(data.exec);
// }

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)av;
	if (ac != 1)
		return (1);
	int_main_init(&data, envp);
	while (1)
	{
		if (int_main_loop(&data) == 1)
			break ;
		continue ;
	}
	freeing(data.exec);
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
static void	int_main_init(t_data *data, char **envp)
{
	ft_bzero(data, sizeof(t_data));
	data->exec = malloc(sizeof(t_list));
	ft_bzero(data->exec, sizeof(t_list));
	get_splitted_path(data->exec);
	envp_to_envparray(envp, data->exec);
	signal(SIGINT, handle_cntrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(EOF, handle_cntrl_d);
}

// line = (user press enter only)
// *line = "" (checking within the string of its empty, line[][])
// static char	*int_main_loop(t_data *data, char *line)
// {
// 	char	**args;
//
// 	data->exit_code = 0;
// 	if (line && *line)
// 	{
// 		args = ft_split(line, ' ');
// 		built_ins(args, data);
// 		add_history(line);
// 		free_double_array(args);
// 	}
// 	free(line);
// 	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
// 	return (line);
// }

static int	int_main_loop(t_data *data)
{
	char	*line;
	char	**args;

	line = readline("\033[0;32mshellfish 🦪🐠🐚 $\033[0m ");
	if (!line)
	{
		free(line);
		return (1);
	}
	args = ft_split(line, ' ');
	built_ins(args, data);
	add_history(line);
	if (g_signal != 0)
	{
		data->exit_code = g_signal;
		g_signal = 0;
	}
	free_double_array(args);
	free(line);
	return (0);
}
