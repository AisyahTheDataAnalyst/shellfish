/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:07:01 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/18 01:15:24 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fd = file descriptor
// 	0 = reading input
// 	1 = writing output
// 	2 = writing error message
//	>=3 = custom fd returned by open(), sockets, other I/O operations
// 	negative = INVALID

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
#include <stdio.h>

int	main()
{
	char str[] = "Aloha!";
	int fd = 1;
	ft_putendl_fd(str, fd);
	return(0);
}
*/