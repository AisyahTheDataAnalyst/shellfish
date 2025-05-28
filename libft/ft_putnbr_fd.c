/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:04:45 by yelu              #+#    #+#             */
/*   Updated: 2024/11/21 17:32:20 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}	
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		digit = (n % 10) + 48;
		write(fd, &digit, 1);
	}
}


int main()
{
    // Test output to stdout (file descriptor 1)
    printf("Testing ft_putnbr_fd with stdout (fd = 1):\n");
    ft_putnbr_fd(1234, 1);
    ft_putnbr_fd(-5678, 1);
    ft_putnbr_fd(0, 1);
    ft_putnbr_fd(-2147483648, 1);

    // Test output to stderr (file descriptor 2)
    printf("\nTesting ft_putnbr_fd with stderr (fd = 2):\n");
    ft_putnbr_fd(9876, 2);        // Expected: 9876
    ft_putnbr_fd(-4321, 2);       // Expected: -4321
    ft_putnbr_fd(0, 2);           // Expected: 0

    return 0;
}
