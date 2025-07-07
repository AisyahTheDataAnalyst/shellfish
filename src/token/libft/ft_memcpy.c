/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:18:54 by yelu              #+#    #+#             */
/*   Updated: 2024/11/11 18:06:59 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp_dest;
	char	*temp_src;

	if (dest == NULL && src == NULL)
		return (0);
	temp_dest = (char *) dest;
	temp_src = (char *)src;
	while (n > 0)
	{
		*(temp_dest++) = *(temp_src++);
		n--;
	}
	return (dest);
}
/**
int main()
{
    int i = 0;
    char dst[6] = "aaaaaa";
    char src[8] = "bbbb";
    memcpy(dst, src, 4);
    dst[4] = '\0';
    while (dst[i])
    {
        printf("%c", dst[i]);
        i++;
    }
    return 0;
}
**/