/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:45:39 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/26 09:11:07 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copywords = imagine therere delimeters in front of the sentence
// 		purpose - to copy words in between delimeters
// s += wordlen = to skip through the words and go to the next delimeter 
// 		to copy the next word

#include "libft.h"

// size_t	ft_wordcount(char const *s, char c);
char			**ft_split(char const *s, char c);
static char		**ft_copywords(char **result, char const *s, char c);

// size_t	ft_wordcount(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

static char	**ft_copywords(char **result, char const *s, char c)
{
	size_t	word_len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (ft_strchr(s, c) == NULL)
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			result[i] = ft_substr(s, 0, word_len);
			if (!result[i])
			{
				ft_freewords(result, i);
				return (NULL);
			}
			i++;
			s += word_len;
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	totalwords;
	char	**array;

	if (!s)
		return (NULL);
	totalwords = ft_wordcount(s, c);
	array = malloc(sizeof(char *) * (totalwords + 1));
	if (!array)
		return (NULL);
	if (!ft_copywords(array, s, c))
		return (NULL);
	array[totalwords] = NULL;
	return (array);
}

/*
#include <stdio.h>

int	main()
{
       	char const *s = "This is my golden chance!";
	char **v = ft_split(s, ' ');
	size_t	i = 0;

	if (!v)
	{
		printf("The string in null, or ft_split fail");
		return (1);
	}

	while (v[i])
	{
		printf("%s\n", v[i]);
		free(v[i]);
		i++;
	}
	free(v);
	return (0);
}*/
