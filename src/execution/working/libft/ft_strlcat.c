/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:47:26 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/12 14:22:28 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1 - process the dst first, with 2 control, dstsize & dst not null
// 2 - then, process the same for src by appending src to dst 1by1 
// 		- allocating +1 for '\0'
// 		- thats why (i + j + 1) < dstsize ((control 1))
// 		- src[j] ((control 2))
// 3 - must have if statement to prevent buffer overflow
// 4 - return is original number of total cat without caring the num of dstsize
// 4.1 - can also return the concatenated str as in the int main

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (dstsize > 0 && i < dstsize - 1)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>

int main()
{
    char dst0[7] = "Hi ";
    char dst1[7] = "Hi ";
    char dst2[7] = "Hi ";
    const char src0[] = "Pamela";
    const char src1[] = "Jimmy";
    const char src2[] = "Lesliee";

    size_t result0 = ft_strlcat(dst0, src0, sizeof(dst0));
    printf("Result: %zu, dst: %s\n", result0, dst0);

    size_t result1 = ft_strlcat(dst1, src1, sizeof(dst1));
    printf("Result: %zu, dst: %s\n", result1, dst1);

    size_t result2 = ft_strlcat(dst2, src2, sizeof(dst2));
    printf("Result: %zu, dst: %s\n", result2, dst2);

    return 0;
}*/