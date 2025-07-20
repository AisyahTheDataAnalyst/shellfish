/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:20:31 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/18 01:50:13 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return; = exit the fn immediately
// int = can handle number more than 1 digit
// recursive logic

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/*
#include <stdio.h>

int	main()
{
	int n = -1666; 
	//going to use putnbr,no need to have '' to represent numbers
	int fd = 1;
	ft_putnbr_fd(n, fd);
	printf("\n");
	return(0);
}*/