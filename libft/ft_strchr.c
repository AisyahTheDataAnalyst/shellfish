/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:50:59 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/26 09:49:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c can also possibly be '\0' 
// noneedl to say if (!s) return NULL coz if input is NULL, its undefined anyway
// unsigned char to handle valid range only: 0 - 255
// unsigned char can handle 0 to 255, signed char handle -128 to 127
// char is ambiguous,can be by default as signed/unsigned depends on the system
// -ve values (-128 to -1) does not represent valid character codes
// 		- according to ASCII or extended ASCII standards
// if still process -ve num,undefined behaviour occurs
// 		- not valid ASCII character
//		- but if still got -ve value
//		- signed char -10 (+256) => unsigned char 246
// 		- signed char -1 (+256) => unsigned char 255 
//		- (out of signed char range) -200 (+256) => unsigned char 56 = ascii 56

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main ()
// {
// 	const char *str = "Tutorial in rural accent";
// 	char ch = 'i';
// 	char *result = ft_strchr(str, ch);
// 	printf("%s\n", result);

// 	if (result != NULL)
// 		printf("Character %c found at position %zdth\n", ch, result - str + 1);
// 	else
// 		printf("Character %c is not found\n", ch);

// 	int index = result - str + 1;
// 	printf("Character %c found at the position %dth\n", ch, index);

// 	char *result1 = ft_strchr(str, 'r');
// 	printf("Occurances of character 'r' in the string:\n");
// 	while (result1 != NULL)
// 	{
// 		printf("Found at %zdth position.\n", result1 - str + 1);
// 		result1 = ft_strchr(result1 + 1, 'r');
// 	}

// 	return (0);
// }
