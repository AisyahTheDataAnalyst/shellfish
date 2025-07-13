/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:46:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/01/30 10:05:26 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// const char* = +/- must only check only 1 sign either one,if many signs,quit
// hence must use if instead of while loop
// ends with numbers iteration, then any other characters are ignored
// it dosent handle NULL input so no need to check is str is NULL 
// will have undefined behaviour if out of range input, no need int min/max
// use long for use case when result = 2147483648 (biggest for + is 21..7) 
// 			- later will become -ve
// 			- handle over/underflow scenarios when converting str to int

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

// #include <stdio.h>
// int	main()
// {
// 	char	text0[] = "abc123";
// 	char	text1[] = "   	-147";
// 	char	text2[] = "  ++--34567";
// 	char	text3[] = "  +-34567";

// 	printf("%d\n", ft_atoi(text0));
// 	printf("%d\n", ft_atoi(text1));
// 	printf("%d\n", ft_atoi(text2));
// 	printf("%d\n", ft_atoi(text3));
// 	return (0);
// }