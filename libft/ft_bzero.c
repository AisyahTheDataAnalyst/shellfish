/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:47:46 by yelu              #+#    #+#             */
/*   Updated: 2024/11/11 18:05:25 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n > 0)
	{
		*temp++ = 0;
		n--;
	}
}
/**
int main()
{
    int i = 0;
    char bef[9] = "ABCDEF";
    printf("Before changing: \n");
    while (bef[i] != '\0')
    {
    printf("%c",bef[i]);
    i++;
    }
    printf("\n");
    ft_bzero(bef, 3);
    printf("After changing: \n");
    for (int k = 0; k < 7; k++)
    {
    printf("%i ", bef[k]);
    }
}
**/