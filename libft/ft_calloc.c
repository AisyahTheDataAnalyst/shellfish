/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:07:18 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/08 11:48:40 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the highlight of calloc is the def of ptr, before it is error handlings only
// purpose of calloc : malloc (allocate memory) + bzero (initialize to 0)
// check for zero elements or zero size
// check for multiplication overflow
// - count = represents num of elements u want to allocate memory for
// - size = represents size of each element in bytes
// - SIZE_MAX = max value held by size_t,depends on the system (32-bit/64-bit)
// - if (count > SIZE_MAX / size) = making sure multipilcation wont overflow
// - SIZE_MAX / size => gives max possible count value so that
// 		count*size multiplication will not overflow  
// - cannot do if (SIZE_MAX < count*size) = issue = checking itself might 
// 			overflow
// void *malloc(size_t size) , thus, return void * aligns with all the returns
// int main = use %d for (char *)memory[i]; char will auto promoted to int  
// 			- asking for its numeric value instead of its character. 

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t count = 5;
	size_t size = sizeof(char);
	void *memory = ft_calloc(count, size);
	
	size_t i = 0;
	char *byte_ptr = (char *)memory;

	if (memory == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}

	while (i < count)
	{
		printf("Byte %zu: %d\n", i, byte_ptr[i]);
		i++;
	}		

	free(memory);
	return (0);

}*/