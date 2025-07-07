/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:20:26 by yelu              #+#    #+#             */
/*   Updated: 2024/11/18 15:11:27 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(long nbr);
static char	*pre_conv(int len);
static void	aft_conv(long nbr, char *result, int *len);

char	*ft_itoa(int n)
{
	long	nbr;
	char	*result;
	int		len;
	int		i;

	nbr = (long)n;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr == 0)
		return (ft_strdup("0"));
	len = count_num(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	aft_conv(nbr, result, &i);
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * (sizeof(char)));
	if (!tmp)
		return (NULL);
	return (tmp);
}

static void	aft_conv(long nbr, char *result, int *len)
{
	while (nbr != 0)
	{
		result[*len] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		(*len)--;
	}
}

static int	count_num(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
/**
int main()
{
	int num = -9865;
	char *result = ft_itoa(num);

	if (result)
	{
		printf("Result: %s\n", result);		
		printf("%s\n", ft_itoa(0));               // Output: "0"
		printf("%s\n", ft_itoa(-2147483648));     // Output: "-2147483648"
		printf("%s\n", ft_itoa(12345));           // Output: "12345"
		printf("%s\n", ft_itoa(-12345));          // Output: "-12345"
	}
	else
		printf("Something failed");
}
**/