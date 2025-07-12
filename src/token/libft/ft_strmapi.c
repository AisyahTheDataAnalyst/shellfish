/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:27:43 by yelu              #+#    #+#             */
/*   Updated: 2024/11/14 18:37:05 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
/**
char	to_uppercase(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return c -('a' - 'A');
	return c;
}
int main()
{
	char s[] = "hello world";
	char *result = ft_strmapi(s, to_uppercase);

	if (result)
	{
		printf("Original: %s\n", s);
		printf("Transformed: %s\n", result);
		free(result);
	}
	return (0);
}
**/