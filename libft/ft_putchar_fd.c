/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:36:11 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/18 01:06:01 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// have to put & in &c to give the address of c in write
// - write expects a pointer of a memory location
// - use &c to give it the memory address where c is stored
// WRONG > if directly use c, passing the value of the character
// cannot do if !c return ch = NULL, coz NULL is a void *

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
#include <stdio.h>

int main ()
{
	char ch = 'A';
	int fd = 1;

	ft_putchar_fd(ch, fd);
	printf("\n");
	return (0);
}
*/