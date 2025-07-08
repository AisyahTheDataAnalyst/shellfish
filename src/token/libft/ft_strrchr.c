/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:44:23 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 15:24:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	if (ch == '\0')
	{
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/**
int main()
{
    char str[] = "hello";
    char *result; 
    result = ft_strrchr(str, 'o');

    if (result)
    {
        printf("Character: %s\n", str);
        printf("The position is at: %li\n", result - str);
    }
    else
        printf("Character not found");

}
**/