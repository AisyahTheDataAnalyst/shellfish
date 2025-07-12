/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:25:32 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/20 19:25:39 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// its a a correct approach to use unsigned char in all memory manipulation fn 
// 		align with the original mem fns
// 		ensures consistent behaviour accross platforms that
// 			 can be signed / unsigned by default differently

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len > 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}
/*
#include <stdio.h>

int	main()
{
	char str[] ="hello";
	printf("%s\n", str);
	ft_memset(str, '#', 3);
	printf("%s\n", str);
}*/
