/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/18 13:30:03 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_exit(char **av, t_data *data);
static void	exit_error_handling_1(char **av, t_data *data);
static void	exit_error_handling_2(char **av, t_data *data);

void	bi_exit(char **av, t_data *data)
{
	if (!av[1])
	{
		freeing(data->exec);
		data->exit_code = 0;
		exit(0);
	}
	exit_error_handling_1(av, data);
	exit_error_handling_2(av, data);
}

// exit(2) for invalid 1st argument
// exit(1) for more than 1 arguments
static void	exit_error_handling_1(char **av, t_data *data)
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
				printf("exit\nshellfish: \
exit: %s: numeric argument required\n", av[i]);
				freeing(data->exec);
				data->exit_code = 2;
				exit(2);
			}
		}
	}
}

static void	exit_error_handling_2(char **av, t_data *data)
{
	int	i;
	int	num;

	i = 1;
	if (av[++i] != NULL)
	{
		printf("exit\nshellfish: exit: too many arguments\n");
		data->exit_code = 1;
		return ;
	}
	num = ft_atoi(av[1]) % 256;
	freeing(data->exec);
	data->exit_code = num;
	exit(num);
}
