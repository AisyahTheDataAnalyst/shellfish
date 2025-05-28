/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelu <yelu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:32:40 by yelu              #+#    #+#             */
/*   Updated: 2024/11/16 15:28:32 by yelu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/**
int main(void) {
    // Test with standard output (fd 1)
    ft_putchar_fd('A', 1);

    // Test with a file
    int fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);
    if (fd != -1) {
        ft_putchar_fd('B', fd);
        close(fd);
    }

    return 0;
}
**/