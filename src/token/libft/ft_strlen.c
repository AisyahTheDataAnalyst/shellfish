/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:42:21 by yelu              #+#    #+#             */
/*   Updated: 2024/11/13 12:59:05 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*s)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		i++;
		count++;
	}
	return (count);
}
/**
int main()
{
    char s[]= "ababaaaMy name is Simonbbaaabbad";
    size_t length = ft_strlen(s);
    printf("The total length is %zu\n", length);
}
**/