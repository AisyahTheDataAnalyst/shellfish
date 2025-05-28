/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:06:37 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 17:31:08 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n > 0)
	{
		*str = (char)c;
		str++;
		n--;
	}
	return (s);
}

int main()
{
    char str[30] = "ABCDEFGHIJKLM";
    ft_memset(str,'a',6);
    printf("Result: %s", str);
}
