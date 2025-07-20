/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:29:24 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 12:55:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// +1 for null terminator
// s_len > start, thats why s_len - start = len
// both size_t and unsigned int are unsigned , so no worries no -ve values
// unsigned int = positive only
// size_ t = lengths depend on size of MEMORY / ARRAYS + len used in malloc
// str = malloc etc first only then if str = null bcoz str is not called in
// 		the equation

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substring_len;
	size_t	s_len;
	char	*str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	substring_len = s_len - start;
	if (len > substring_len)
		len = substring_len;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	const char *s = "Hello my darling";
// 	unsigned int start = 7;
// 	size_t len = 7;
// 	char *result = ft_substr(s, start, len);

// 	printf("Original text: %s\n", s);
// 	if (!result)
// 		printf("No memory allocation for the substring\n");
// 	else
// 		printf("Substring: %s\n", result);
// 	free(result);
// 	return(0);
// }
