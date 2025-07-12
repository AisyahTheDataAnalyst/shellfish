/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:52:47 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 14:27:26 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start])
	{
		if (s1[start] && ft_strchr(set, s1[start]))
			start++;
		else
			break ;
	}
	end = ft_strlen(s1);
	if (s1[end] == '\0')
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
	len = end - start + 1;
	trimmed = malloc(len);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len);
	return (trimmed);
}

/*
#include <stdio.h>

int	main()
{
	char const *text1 = "abHelloab";
	char const *text2 = "aaabbbHellobbbab";
	char const *text3 = "abbbaaabab";
	char const *text4 = NULL;
	char const *set = "ab";
	char *result1 = ft_strtrim(text1, set);
	char *result2 = ft_strtrim(text2, set);
	char *result3 = ft_strtrim(text3, set);
	char *result4 = ft_strtrim(text4, set);

	printf("Before: %s\nAfter: %s\n\n", text1, result1);
	printf("Before: %s\nAfter: %s\n\n", text2, result2);
	printf("Before: %s\nAfter: %s\n\n", text3, result3);
	printf("Before: %s\nAfter: %s\n", text4, result4);
	return(0);
}
*/