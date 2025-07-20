/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:28:49 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 14:24:42 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// original memchr also use unsigned char
// memchr = search for the 1st occurrence of a character in a block of memory
// no need if c is null because it will have undefined behavour/error anyway
// not required to do error handling in mem, align with real mem fns, 
// 		relies on the caller to ensure arguments are valid

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	m;

	ptr = (unsigned char *)s;
	m = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == m)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main ()
{
	const char *mem = "b10bj##bbbklkbb";
	char ch1 = 'b';
	char ch2 = 'l';
	size_t measure = 5;
	char *result1 = ft_memchr(mem, ch1, measure);
	char *result2 = ft_memchr(mem, ch2, measure);

	printf("Mem : %s\n", mem);
	if (!result1)
		printf("%c is not within the first %zd words\n", ch1, measure);
	else
		printf("Located %c at %zd position\n", ch1, result1 - mem + 1);
	//
	if (!result2)
		printf("%c is not within the first %zd words\n", ch2, measure);	
	else
		printf("Located %c at %zd position\n", ch2, result2 - mem + 1);
	//
	return (0);
}*/
