/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:38:35 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/18 01:19:23 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *s (just s in write) = pointer arithmetic
// s[i] (just &s[i] in write) = array indexing
// since has write, no need use printf for this function in the int main

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char	*str = "Hi!";
	int	fd = 1;

	ft_putstr_fd(str, fd);
	printf("\n");
	return (0);

}*/
