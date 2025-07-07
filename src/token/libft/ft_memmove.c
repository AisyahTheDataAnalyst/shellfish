/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:48:07 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 17:30:09 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	if (dest == NULL && src == NULL)
		return (0);
	if (n == 0 || dest == src)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (temp_dest < temp_src)
	{
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_dest = temp_dest + n;
		temp_src = temp_src + n;
		while (n--)
			*(--temp_dest) = *(--temp_src);
	}
	return (dest);
}

/**
int main()
{
    int i = 0;
    int j = 0;
    char str[10] = "AAAAAA";
    char dest[10] = "BBBCCCCC";
    printf("Before:\n");
    while (dest[i])
    {
        printf("%c", dest[i]);
        i++;
    }
    printf("\n");
    ft_memmove(dest, str, 6);
    printf("After: \n");
    while (dest[j])
    {
        printf("%c", dest[j]);
        j++;
    }
}
**/