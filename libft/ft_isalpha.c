/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:45:13 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 14:14:44 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	return (0);
}

/* 
 #include <stdio.h>

int	main()
{
	int	n = '9'; //if without '' considered as ascii, if in '' is a number
	int m = 'a';

	if (ft_isalpha(n))
		printf("n is an alphabet\n");
	else
		printf("n is not an alphabet\n");

	if (ft_isalpha(m))
		printf("m is an alphabet\n");
	else
		printf("m is not an alphabet\n");
	return (0);


*/
