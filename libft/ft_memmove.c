/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:52:26 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 21:08:06 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	must use const char, or else the before version will be altered
// 		in the output of int main 

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (n == 0)
		return (d);
	if (s == NULL)
		return (NULL);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dst);
}
/*
#include <stdio.h>

int main ()
{
	char buffer[] = "1234567890";
	size_t len = 3;

	printf("Before: %s\n", buffer);	
	ft_memmove(buffer, buffer + 2, len);
	printf("After: %s\n", buffer);
	return(0);
}*/
