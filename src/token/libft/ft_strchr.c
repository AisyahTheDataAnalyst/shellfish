/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:46:02 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 13:48:58 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	if (ch == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == ch)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
/**
int main()
{
	const char str[] = "hellHo";
	char *result = ft_strchr(str, 'H');

	if (result)
	{
		printf("Character: %s\n", result);
		printf("Found character at index: %i\n", result - str);
	}
	else
		printf("Character not found\n");
} 
**/