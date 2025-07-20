/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:42:20 by aimokhta          #+#    #+#             */
/*   Updated: 2025/04/28 17:12:11 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// unsigned char - better practice esp on raw memory manipulation fn
// 		- align with how real bzero works also
// another way to do is to use memset
// since this is a ray memory maipulation fn, - no usages of null terminating
// no error handling of if (n ++ 0) is needed,unnecessary cluter&complexity
// 		- it will just skip the loop and its a no-op(does nothing)
// output: will null terminate the 1st n characters, but will not have output
// 			- no output coz already null terminated
// 			- %.5s is to show at most 5 characters only 
// 				(but nothing printed since the front has been null terminated)
//	parameter void * => can take any data type: int/ char/ float/ char *
// <<char *>>
// initialize also string to NULL, because 
// putting number 0 at the index 0, = same as putting \0 at the index 0
// essentialyy turning it into a null string because C strings are terminated
// first '\0' at the index 0 is encountered
// <<int>>
// ft_bzero(&num, sizeof(int)); &num gives the ADDRESS of num
// goes thru each byte of the memory block in hex
// 		int has 4 bytes, those 4 bytes are set to 0
// this is how it looks like in the memory:
// => ex: 12345 => 00 00 30 39 (hex) => 00 00 00 00

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>

int	main()
{
	char	s[] = "Aloha";
	size_t	n = 3;
	
	printf("Before ft_bzero : %s\n", s);
	ft_bzero(s, n);
	printf("After ft_bzero : %.5s\n", s); //Output: \0\0\0ha 
	return (0);
}*/
