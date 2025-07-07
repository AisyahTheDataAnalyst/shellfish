/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:47:53 by yelu              #+#    #+#             */
/*   Updated: 2024/11/11 17:42:33 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (1);
	else
		return (0);
}

/*
int main()
{
    int digit = '9';
    int result = ft_isdigit(digit);
    printf("Result: %d\n", result);
}
*/