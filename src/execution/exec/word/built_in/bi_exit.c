/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:30:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/08/01 12:41:44 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void				bi_exit(char **av, t_exc *exc);
static void			exit_isdigit_only(char **av, t_exc *exc, int i, int j);
static int			exit_1argonly_nottoobignum(char **av, t_exc *exc);
static void			exit_int128_mod256(char **av, t_exc *exc);
static __int128_t	ft_ato_int128(const char *str);
// static void			print_int128(__int128_t n);

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
	exit_isdigit_only(av, exc, i, j);
	if (exit_1argonly_nottoobignum(av, exc) == 1)
		return ;
	exit_int128_mod256(av, exc);
}

// exit(2) for invalid 1st argument
// exit(1) for more than 1 arguments
static void	exit_isdigit_only(char **av, t_exc *exc, int i, int j)
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
				ft_putendl_fd("exit", 2);
				ft_putstr_fd("shellfish: exit: ", 2);
				ft_putstr_fd(av[i], 2);
				ft_putendl_fd(": numeric argument required", 2);
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
static int	exit_1argonly_nottoobignum(char **av, t_exc *exc)
{
	int			i;

	i = 1;
	if (av[++i] != NULL)
	{
		ft_putendl_fd("exit", 2);
		ft_putendl_fd("shellfish: exit: too many arguments", 2);
		exc->exit_code = 1;
		return (1);
	}
	if (ft_strlen(av[1]) > 20)
	{
		ft_putendl_fd("exit", 2);
		ft_putstr_fd("shellfish: exit: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exc->exit_code = 2;
		if (exc->process->pipe_flag == false)
		{
			free_before_readline(exc);
			freeing(exc);
		}
		exit(2);
	}
	return (0);
}

// if (num < -9223372036854775808 || num > 9223372036854775807)
static void	exit_int128_mod256(char **av, t_exc *exc)
{
	__int128_t	num;

	num = ft_ato_int128(av[1]);
	if (num < (__int128_t)LLONG_MIN || num > (__int128_t)LLONG_MAX)
	{
		ft_putendl_fd("exit", 2);
		ft_putstr_fd("shellfish: exit: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exc->exit_code = 2;
		if (exc->process->pipe_flag == false)
		{
			free_before_readline(exc);
			freeing(exc);
		}
		exit(2);
	}
	exc->exit_code = (unsigned char)(num % 256);
	printf("exit\n");
	if (exc->process->pipe_flag == false)
	{
		free_before_readline(exc);
		freeing(exc);
	}
	exit((unsigned char)(num % 256));
}

// theres no % for printf for __int128_t
static __int128_t	ft_ato_int128(const char *str)
{
	int			i;
	int			sign;
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

// static void	print_int128(__int128_t n)
// {
// 	char	buf[50]; // Enough for 39 digits + sign + null
// 	int		i = 49;
// 	int		is_negative = 0;

// 	buf[i--] = '\0';
// 	if (n == 0)
// 	{
// 		write(1, "0", 1);
// 		return;
// 	}
// 	if (n < 0)
// 	{
// 		is_negative = 1;
// 		n = -n;
// 	}
// 	while (n > 0)
// 	{
// 		buf[i--] = '0' + (n % 10);
// 		n /= 10;
// 	}
// 	if (is_negative)
// 		buf[i--] = '-';
// 	write(1, &buf[i + 1], 49 - i);
// }
