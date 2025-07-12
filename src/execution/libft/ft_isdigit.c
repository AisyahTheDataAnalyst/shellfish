/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:46:14 by aimokhta          #+#    #+#             */
/*   Updated: 2024/11/06 19:11:11 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
	//if without '' considered as ascii, if in '' is a number
	int	n = 9;
	int m = '9';

	if (ft_isdigit(n))
		printf("n is a digit\n");
	else
		printf("n is not a digit\n");

	if (ft_isdigit(m))
		printf("m is a digit\n");
	else
		printf("m is not a digit\n");
	return (0);
}*/