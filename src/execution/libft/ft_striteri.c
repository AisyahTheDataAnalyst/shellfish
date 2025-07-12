/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:17:33 by aimokhta          #+#    #+#             */
/*   Updated: 2024/12/17 21:56:51 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// unsinged int = positive int only + generic non-ve num usages
// size_t = positive only + for sizes(memory/spaces) coz adapts to the system
// cannot s[i] = f(... because that implies you want to return smthg
// - return type is void
// - you directly edit the original string
// &s[i] = (s + i)

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>

static void ft_toupper_mock(unsigned int i, char *str)
{
	(void)i;
	
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
}
// Avoid modifying 'i' since it's not used here, 
// but it's part of the function signature

int	main()
{
	char str[] = "hello";	
	printf("Before: %s\n", str);
	ft_striteri(str, ft_toupper_mock);
	printf("After: %s\n", str);
	return (0);
*/