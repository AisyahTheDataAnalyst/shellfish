/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:53 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/14 13:30:54 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

// #include <stdio.h>

// int main ()
// {
// 	const char *str = "Hello";
// 	size_t result = ft_strlen(str);

// 	printf("Text : %s\n Numbers of characters : %zd\n", str, result);
// 	return (0);
// }
