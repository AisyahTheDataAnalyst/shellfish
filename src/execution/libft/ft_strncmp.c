/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:39:10 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 20:57:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main ()
{
	const char *s1 = "Rainy day";
	const char *s2 = "Rainbow";
	const char *s3 = "Rain";
	const char *s4 = "Rainy night";
	size_t n = 5;
	int cmp1 = ft_strncmp(s1, s2, n);
	int cmp2 = ft_strncmp(s1, s3, n);
	int cmp3 = ft_strncmp(s1, s4, n);

	printf("Compare the first 5 words between %s & %s : %d\n", s1, s2, cmp1);
	printf("Compare the first 5 words between %s & %s : %d\n", s1, s3, cmp2);
	printf("Compare the first 5 words between %s & %s : %d\n", s1, s4, cmp3);
	return (0);
}*/
