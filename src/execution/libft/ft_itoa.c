/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:46:22 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 12:54:10 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// don't need to explicitly cast from int to long int in C is because 
//  - integer types in C automatically promote or widen
// %modulo = "Backward Processing"/ "Reverse Iteration"
// = every single digit processed in reverse order 
// - right to left processing
// - use % in =>  (num % 10) + '0';
//
// void *malloc, so no need to cast malloc into char *
// - its already defined by (char *)result
//
// (num < 0) , len++ because want to add in the '-' into the counter 
// - when (len > i)
//
// if want to test as nothing turn in, use 0 (int), as NULL for pointer types

#include "libft.h"

static int	ft_getdigit(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	long	len;
	char	*result;
	int		i;

	num = n;
	len = ft_getdigit(num);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	i = 0;
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
		i = 1;
	}
	while (len-- > i)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

// #include <stdio.h>
//
// int	main()
// {
// 	int num = 124;
// 	char *numstr = ft_itoa(num);
//
// 	printf("%d that was an interger now is a string : %s\n", num, numstr);
// 	free (numstr);
// 	return (0);
// }