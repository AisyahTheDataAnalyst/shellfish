/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:49:53 by yelu              #+#    #+#             */
/*   Updated: 2024/11/11 17:47:27 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if ((alnum >= 48 && alnum <= 57) || (alnum >= 65 && alnum <= 90)
		|| (alnum >= 97 && alnum <= 122))
		return (1);
	else
		return (0);
}

/**
int main()
{
    int c = '9';
    int result = ft_isalnum(c);
    printf("Result: %d\n", result);

}
**/