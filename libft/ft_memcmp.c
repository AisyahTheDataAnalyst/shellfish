/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:00:03 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 14:25:10 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memcmp = compare two block of memory the differences between the characters 
// 		in ASCII differences, but just within the 1st number of characters of n
// real memcmp also use unsigned char *

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main ()
{
	const char *str1 = "asdfghjkl789zxcvbnm123";
	const char *str2 = "asdfg#hjklzxcvbnm";
	size_t size1 = 3;
	size_t size2 = 6;
	size_t size3 = 0;
	int result1 = ft_memcmp(str1, str2, size1);
	int result2 = ft_memcmp(str1, str2, size2);
	int result3 = ft_memcmp(str1, str2, size3);

	printf("STR1 = %s\nSTR2 = %s\n", str1, str2);
	printf("The differences between them in:\n");
	printf("The first %zd words = %d\n", size1, result1);
	printf("The first %zd words = %d\n", size2, result2);
	printf("The first %zd words = %d\n", size3, result3);
	return(0);
}*/
