/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:35:54 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 10:33:06 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;
	unsigned char		ch;

	str = (const unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return ((unsigned char *)s + i);
		}
		i++;
	}
	return (0);
}
/**
int main()
{
	const char s[6] = "Hello";
	char c;
	size_t n = 6;
	c = 'l';

	char *result;
	result = ft_memchr(s, c, n);
	printf("Result: %s\n", result);
	return (0);
}
**/