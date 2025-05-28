/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:46:13 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 14:54:38 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_allocate(char **tab, char const *s, char delim);
static int	word_count(const char *str, char c);

static void	ft_allocate(char **tab, char const *s, char delim)
{
	char		**tab_p;
	char const	*str;

	str = s;
	tab_p = tab;
	while (*str)
	{
		while (*s == delim)
			++s;
		str = s;
		while (*str && *str != delim)
			++str;
		if (*str == delim || str > s)
		{
			*tab_p = ft_substr(s, 0, str - s);
			s = str;
			++tab_p;
		}
	}
	*tab_p = NULL;
}

static int	word_count(char const *s, char delim)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == delim)
			++s;
		if (*s)
			++count;
		while (*s && *s != delim)
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;

	if (!s)
		return (NULL);
	size = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	ft_allocate(str, s, c);
	return (str);
}

/**
int main() {
    char **result;
    int i;

    // Test case 1: Simple split
    printf("Test Case 1: Simple split\n");
    result = ft_split("Hello world, how are you?", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    }
    printf("\n");

    // Test case 2: Multiple spaces between words
    printf("Test Case 2: Multiple spaces\n");
    result = ft_split("Hello    world     how  are    you?", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    }
    printf("\n");

    // Test case 3: Empty string
    printf("Test Case 3: Empty string\n");
    result = ft_split("", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    } else {
        printf("No words found\n");
    }
    printf("\n");

    // Test case 4: String with only delimiters
    printf("Test Case 4: Only delimiters\n");
    result = ft_split("   ", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    } else {
        printf("No words found\n");
    }
    printf("\n");

    // Test case 5: Delimiter at the start and end
    printf("Test Case 5: Delimiters at start and end\n");
    result = ft_split("   Hello world  ", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    }
    printf("\n");

    // Test case 6: No delimiters, one word
    printf("Test Case 6: Single word\n");
    result = ft_split("Hello", ' ');
    if (result) {
        for (i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free each word after use
        }
        free(result);  // Free the result array
    }
    printf("\n");

    return 0;
}
**/