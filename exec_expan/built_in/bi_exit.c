/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/27 13:01:56 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_exit(char **av, t_list *exec);
static void	exit_error_handling(char **av);

void	bi_exit(char **av, t_list *exec)
{
	if (!av[1])
	{
		if (exec->envp_array != NULL)
			free_double_array(exec->envp_array);
		free_double_array(exec->splitted_path);
		rl_clear_history();
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	exit_error_handling(av);
	if (exec->envp_array != NULL)
		free_double_array(exec->envp_array);
	free_double_array(exec->splitted_path);
	rl_clear_history();
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

static void	exit_error_handling(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (av[i])
	{
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 1)
				j++;
			else
			{
				printf("exit\nexit: %s: numeric argument required\n", av[i]);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (av[++i] != NULL)
	{
		printf("exit\nexit: too many arguments\n");
		exit(1);
	}
}
