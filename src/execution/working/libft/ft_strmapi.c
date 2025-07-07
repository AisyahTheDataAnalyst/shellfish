/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:42:56 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/17 20:56:19 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// purpose = create a new string by applying a CUSTOM fn to EACH CHAR given str
// (f) => "index of the character"
// char as in (unsigned int, char) => character itself as the argument
// flexibility to define your own fn
// (*f) => function pointer
// i = to match with f's unsigned int 

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	len;
	int		i;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

static char adding(unsigned int i, char c)
{
	return (i + c);
}

int	main()
{
	char const *str = "hellooooz";
	char *result = ft_strmapi(str,adding);

	printf("Before: %s\nAfter : %s\n", str, result);
	free(result);
	return (0);
}
*/