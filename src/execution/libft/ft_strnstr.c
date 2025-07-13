/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:22:29 by aimokhta          #+#    #+#             */
/*   Updated: 2025/06/19 11:17:11 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// string must dereference the pointer, *little or little[i]
// but , no need for linked list, lst from *lst

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	j = 0;
	while (j < len && big[j])
	{
		i = 0;
		while (big[i + j] == little[i] && (i + j) < len && little[i] != '\0')
			i++;
		if (little[i] == '\0')
			return ((char *)(big + j));
		j++;
	}
	return (NULL);
}

// #include <stdio.h>
//
// int main()
// {
// 	const char *buffer1 = "This is going to be awesome!";
// 	const char *buffer2 = "going";
// 	size_t n0 = 0;
// 	size_t n1 = 4;
// 	size_t n2 = 10; // cut off in the middle of buffer2
// 	size_t n3 = 20;
// 	char *result0 = ft_strnstr(buffer1, buffer2, n0);
// 	char *result1 = ft_strnstr(buffer1, buffer2, n1);
// 	char *result2 = ft_strnstr(buffer1, buffer2, n2);
// 	char *result3 = ft_strnstr(buffer1, buffer2, n3);
//
// 	printf("Haystack = %s\nNeedle = %s\n", buffer1, buffer2);
// 	printf("Search for needle within the first n words of Haystack :\n");
// 	printf("1. n=%zd : %s\n", n0, result0);
// 	printf("2. n=%zd : %s\n", n1, result1);
// 	printf("3. n=%zd : %s\n", n2, result2);
// 	printf("4. n=%zd : %s\n", n3, result3);
// 	return (0);
// }