/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:29:45 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 14:03:13 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (((unsigned char)s1[i]) == ((unsigned char)s2[i]))
		{
			if (s1[i] == '\0')
				return (0);
			i++;
			n--;
		}
		else
		{
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		}
	}
	return (0);
}
/**
int main()
{
    char str1[] = "pello";
    char str2[] = "pelloa";
    int n;

    n = 8; 
    printf("%d\n", ft_strncmp(str1, str2, n));
    return 0;
}
**/
