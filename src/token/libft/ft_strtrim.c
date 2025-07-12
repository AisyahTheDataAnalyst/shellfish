/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:22:37 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 17:38:29 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ischar(const char *set, char c);
static char	*new_str(const char *s1, size_t start, size_t len);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(s1) == 0 || !s1 || !set)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ischar(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (j >= i && ischar(set, s1[j]))
		j--;
	return (new_str(s1, i, (j - (i - 1))));
}

static char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ischar(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// int main()
// {
//     char *result = ft_strtrim("  \t Hello, World! \n  ", " \t\n");
//     printf("Result: '%s'\n", result);
//     free(result);
//     return 0;
// }
