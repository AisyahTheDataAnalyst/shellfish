/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:09:17 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 18:44:26 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If the multiplication of count and size would result in a value 
// larger than what size_t can hold, the function returns NULL.

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	if (count == 0 || size == 0)
	{
		tmp = (malloc(0));
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

/**
int main()
{
	size_t len = 4;
	size_t i = 2;
	int *array = ft_calloc(len, sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
	}

	while (i < len)
	{
		printf("%i", array[i]);
		i++;
	}
	printf("\n");

	free(array);
	return 0;
	
}
**/
