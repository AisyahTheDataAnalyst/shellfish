/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:45:46 by aimokhta          #+#    #+#             */
/*   Updated: 2024/11/06 19:37:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	return (0);
}

/*
 #include <stdio.h>

int	main()
{
	int	n = 126; //if without '' considered as ascii, if in '' is a number
	int m = 130;

	if (ft_isascii(n))
		printf("n is in ASCII\n");
	else
		printf("n is not in ASCII\n");

	if (ft_isascii(m))
		printf("m is in ASCII\n");
	else
		printf("m is not in ASCII\n");
	return (0);
}*/