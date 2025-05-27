/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_squote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:19:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/28 18:53:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// limitation of this function : can only handle normal case
//		(/) 'a a'  => "a a"
//		(/) 'a a's => "a a" , "s"
//		(X) a'aa's => memory leaks (ft_wordcount x kira betul2 
//						tp more than 25 lines if want to fix it :( ) 
//		(X) a's    => segfault
//		(X) '\''   => have 3 squote as a string
char			**ft_split_squote(char const *s, char c);
static size_t	ft_wordcount_squote(char const *s, char c);
static char		**ft_copywords(char **result, char const *s, char c);
static char		*ft_copywords_squote(char const *s);
static char		*ft_copywords_normal(char const *s, char c);

static size_t	ft_wordcount_squote(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
			if (s[i] == '\'')
				i++;
			count++;
		}
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

// ft_substr(start, 0, word_len)
// 0 - where i want to start to substr, index,
//  so the starting point is index 0
// word_len = count of how many words moving forward you want to count
//  count starts from 1, obviously when its not empty
static char	*ft_copywords_squote(char const *s)
{
	size_t		word_len;
	const char	*start;
	char		*result;

	start = s;
	while (*s && *s != '\'')
		s++;
	word_len = s - start;
	result = ft_substr(start, 0, word_len);
	return (result);
}

static char	*ft_copywords_normal(char const *s, char c)
{
	size_t		word_len;
	const char	*start;
	char		*result;

	start = s;
	while (*s && *s != c && *s != '\'')
		s++;
	word_len = s - start;
	result = ft_substr(start, 0, word_len);
	return (result);
}

static char	**ft_copywords(char **result, char const *s, char c)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c && *s != '\'')
			s++;
		if (*s != c && *s != '\'' && *s)
			result[i] = ft_copywords_normal(s, c);
		else if (*s && *s == '\'' && ft_strchr(s, '\'') != ft_strrchr(s, '\''))
		{
			s++;
			result[i] = ft_copywords_squote(s);
			s++;
		}
		word_len = ft_strlen(result[i]);
		s += word_len;
		if (!result[i])
			ft_freewords(result, i);
		i++;
	}
	return (result);
}

char	**ft_split_squote(char const *s, char c)
{
	size_t	totalwords;
	char	**array;

	if (!s)
		return (NULL);
	totalwords = ft_wordcount_squote(s, c);
	array = malloc(sizeof(char *) * (totalwords + 1));
	if (!array)
		return (NULL);
	if (!ft_copywords(array, s, c))
		return (NULL);
	array[totalwords] = NULL;
	return (array);
}

// #include <stdio.h>

// int	main()
// {
//        	char const *s = "This is my 'a a's chance!";
// 	char **v = ft_split_squote(s, ' ');
// 	size_t	i = 0;

// 	if (!v)
// 	{
// 		printf("The string in null, or ft_split fail");
// 		return (1);
// 	}

// 	while (v[i])
// 	{
// 		printf("%s\n", v[i]);
// 		free(v[i]);
// 		i++;
// 	}
// 	free(v);

// 	size_t count = ft_wordcount_squote(s, ' ');
// 	printf("%zu\n", count);
// 	return (0);
// }
