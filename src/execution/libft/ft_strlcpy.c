/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:20:18 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/14 13:32:18 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// behaviour of the strlcpy - always return the total number of src
// at the same time, can also copy within dstsize

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;

	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == '\0')
		return (j);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0' )
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (j);
}

// #include <stdio.h>

// int	main()
// {
// 	char	dst0[6];
// 	char	dst1[13];
// 	char	dst2[25];
// 	char	dst3[5];
// 	const char	*src = "Hello motherrainbows!";
// 	size_t	dstsize;

// 	dstsize = ft_strlcpy(dst0, src, sizeof(dst0));
// 	printf("%zu\n", ft_strlcpy(dst0, src, sizeof(dst0)));
// 	printf("%s\n", dst0);

// 	dstsize = ft_strlcpy(dst1, src, sizeof(dst1));
// 	printf("%zu\n", ft_strlcpy(dst1, src, sizeof(dst1)));
// 	printf("%s\n", dst1);

// 	dstsize = ft_strlcpy(dst2, src, sizeof(dst2));
// 	printf("%zu\n", ft_strlcpy(dst2, src, sizeof(dst2)));
// 	printf("%s\n", dst2);

// 	dstsize = ft_strlcpy(dst3, src, sizeof(dst3));
// 	printf("%zu\n", ft_strlcpy(dst3, src, sizeof(dst3)));
// 	printf("%s\n", dst3);
// }