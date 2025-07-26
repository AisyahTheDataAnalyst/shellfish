/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:42:42 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/26 18:23:58 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void		bi_echo(char **av, t_exc *exc);
static bool	is_option_exist(char **av, int j);
static int	echo_start_printing(char **av, int i, int j);

void	bi_echo(char **av, t_exc *exc)
{
	int		i;
	int		j;
	bool	n_option_exist;

	i = 1;
	j = 1;
	n_option_exist = is_option_exist(av, j);
	i = echo_start_printing(av, i, j);
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!av[1] || n_option_exist == false)
		printf("\n");
	exc->exit_code = 0;
}

// handle cases like -nnnnnnnnnnnnnnn (accept) && -nnnnnnnnnnnnbb (reject)
static bool	is_option_exist(char **av, int j)
{
	if (av[1] && ft_strncmp(av[1], "-n", 2) == 0)
	{
		while (av[1][j])
		{
			if (!ft_strncmp(&av[1][j], "n", 1))
				j++;
			else
				return (false);
		}
		return (true);
	}
	return (false);
}

// to know starting from which variable need to print for echo
static int	echo_start_printing(char **av, int i, int j)
{
	while (av[i] && ft_strncmp(av[i], "-n", 2) == 0)
	{
		while (av[i][j])
		{
			if (av[i][j] == 'n')
				j++;
			else
				return (i);
		}
		i++;
	}
	return (i);
}
