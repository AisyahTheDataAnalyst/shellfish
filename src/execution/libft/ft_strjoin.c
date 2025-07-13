/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:21:38 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/28 16:13:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check !joined after joined = ~~ to check if malloc fails to allocate memory
// strjoin != strlcat , malloc and limitation dstsize

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined [i + j] = s2[j];
		j++;
	}
	joined [i + j] = '\0';
	return (joined);
}

// #include <stdio.h>

// int	main()
// {
// 	const char *s1 = "Good morning.";
// 	const char *s2 = "How are you today?";
// 	char *result = ft_strjoin(s1, s2);

// 	printf("1st sentence: %s\n2nd sentence: %s\n", s1, s2);
// 	printf("Full sentences: %s\n", result);
// 	free (result);
// 	return (0);
// }
