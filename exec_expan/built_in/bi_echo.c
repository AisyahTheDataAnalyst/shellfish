/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:42:42 by aimokhta          #+#    #+#             */
/*   Updated: 2025/05/26 16:52:39 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// kena edit lagi, tambah expansion $?, "'$USER'", '"$USER"', $USER 
void	bi_echo(char **av)
{
	int	i;

	i = 1;
	if (!av[i])
		return ;
	while (av[i] && ft_strncmp(av[i], "-n", 3) == 0)
		i++;
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (ft_strncmp(av[1], "-n", 3) != 0)
		printf("\n");
}
