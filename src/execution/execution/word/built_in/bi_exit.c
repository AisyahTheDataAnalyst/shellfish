/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/07/15 13:41:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void				bi_exit(char **av, t_exc *exc);
static void			exit_error_handling_1(char **av, t_exc *exc, int i, int j);
static void			exit_error_handling_2(char **av, t_exc *exc);
static void			exit_error_handling_3(char **av, t_exc *exc);
static __int128_t	ft_ato_int128(const char *str);

void	bi_exit(char **av, t_exc *exc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!av[1])
	{
		exc->exit_code = 0;
		if (exc->process->pipe_flag == false)
		{
			free_before_readline(exc);
			freeing(exc);
		}
		exit(0);
	}
	exit_error_handling_1(av, exc, i, j);
	exit_error_handling_2(av, exc);
	exit_error_handling_3(av, exc);
}

// exit(2) for invalid 1st argument
// exit(1) for more than 1 arguments
static void	exit_error_handling_1(char **av, t_exc *exc, int i, int j)
{
	if (av[++i])
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
				exc->exit_code = 2;
				if (exc->process->pipe_flag == false)
				{
					free_before_readline(exc);
					freeing(exc);
				}
				exit(2);
			}
		}
	}
}

// 2- control overflow what __int128_t cannot handle 
// which is more than 39 digits
// 9223372036854775807 is 19 digits, so i just make it to 20 digits
static void	exit_error_handling_2(char **av, t_exc *exc)
{
	int			i;

	i = 1;
	if (av[++i] != NULL)
	{
		printf("exit\nshellfish: exit: too many arguments\n");
		exc->exit_code = 1;
		return ;
	}
	if (ft_strlen(av[1]) >= 20)
	{
		printf("exit\n");
		printf("shellfish: exit: %s: numeric argument required\n", av[1]);
		exc->exit_code = 2;
		if (exc->process->pipe_flag == false)
		{
			free_before_readline(exc);
			freeing(exc);
		}
		exit(2);
	}
}

static void	exit_error_handling_3(char **av, t_exc *exc)
{
	__int128_t	num;

	num = ft_ato_int128(av[1]);
	if (num > 9223372036854775807)
	{
		printf("exit\nshellfish: \
exit: %s: numeric argument required\n", av[1]);
		exc->exit_code = 2;
		if (exc->process->pipe_flag == false)
		{
			free_before_readline(exc);
			freeing(exc);
		}
		exit(2);
	}
	num = num % 256;
	exc->exit_code = (unsigned char)num;
	if (exc->process->pipe_flag == false)
	{
		free_before_readline(exc);
		freeing(exc);
	}
	exit((unsigned char)num);
}

// theres no % for printf for __int128_t
static __int128_t	ft_ato_int128(const char *str)
{
	int			i;
	__int128_t	sign;
	__int128_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((result * sign));
}
