/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:30:30 by yelu              #+#    #+#             */
/*   Updated: 2024/11/13 10:26:18 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
/**
int main()
{
	char *str = "Hello world";
	size_t i = 0;
	char *result;

	result = ft_substr(str, 6, 5);
	if (result != NULL)
	{
		while (result[i] != '\0')
		{
			printf("%c", result[i]);
			i++;
		}
		printf("\n");
		free(result);
	}
	else
		printf("Memory allocation failed");
		return (0);
}
**/