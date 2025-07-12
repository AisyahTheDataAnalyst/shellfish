/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:50:34 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 12:54:48 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// no need to do error handling because will have error anyway

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(src) + 1;
	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, size);
	return (dst);
}

// #include <stdio.h>

// int	main()
// {
// 	const char	*src = 	"I am awesome";
// 	char*	dst = ft_strdup(src);

// 	if (src == NULL)
// 		printf("Original text is null\n");
// 	else
// 		printf("Original text = %s\n", src);

// 	if (dst == NULL)
// 		printf("The text cannot be duplicated as the allocation size is 0\n");
// 	else
// 	{
// 		printf("Duplicated text = %s\n", dst);
// 		free(dst);
// 	}
// 	return (0);
// }