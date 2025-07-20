/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:44:11 by aimokhta          #+#    #+#             */
/*   Updated: 2024/11/06 19:37:09 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AL-NUM = Alphanumeric = Alphabet + Number
// return 1 - true
// return 0 - false 

#include "libft.h"

int	ft_isalnum(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int	n = 9; //if without '' considered as ascii, if in '' is a number
	if (ft_isalnum(n))
		printf("n is a number\n");
	else
		printf("n is not a number\n");
	return (0);
}*/