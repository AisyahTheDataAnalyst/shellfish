/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:29:52 by aimokhta          #+#    #+#             */
/*   Updated: 2025/02/08 20:19:17 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use unsigned char like the real memcpy, to avoid edge cases' risks
// memcpy = copy a specific number of bytes from 1 memory location to another

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			i;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return ((void *)cdest);
}
/*
#include <stdio.h>

int	main()
{
	char csrc[] = "Welcome";
	char cdest[] = "What would you like to order?";
	size_t	n = 15;

	printf("%s\n", );
	ft_memcpy(cdest, csrc, n);
	printf("%s\n", );
	return (0);
}*/
