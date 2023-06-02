/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:32:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 23:18:16 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libftprintf.h"
#include <stdio.h>

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int	main(void)
{
	char	*c;
	unsigned long long d = -2147483646;

	c = (char *)malloc(sizeof(char) * 5);
	// printf("%u\n", 42967295);
	// printf("%llu\n", d);
	printf("%X\n%p\n", 1234, c);
	ft_printf("aaa|%i|aaa%%ccc%Xbbb %s  |%p| %d %c %u %x %X\n", 123, 1234, "abcdef", c, 42, 'c', -1, 1234, 1234);
	ft_printf("%d\n%d\n|%d|\n", ft_printf(":aaa:"), ft_printf("%x\n", 1234), ft_printf("%pa%%aa%s%d%u%i\n", c, "123", 123, 12, 999));
	free(c);
	return (0);
}

// int	ft_putnbr_fd_cnt(int n, int digit, int fd)
// {
// 	long long	nbr;

// 	nbr = (long long) n;
// 	if (n < 0)
// 	{
// 		digit++;
// 		write(fd, "-", 1);
// 		nbr *= -1;
// 	}
// 	if (nbr > 9)
// 	{
// 		ft_putnbr_fd(nbr / 10, fd);
// 		ft_putnbr_fd(nbr % 10, fd);
// 	}
// 	else if (0 <= nbr && nbr <= 9)
// 	{
// 		digit++;
// 		nbr += '0';
// 		write(fd, &nbr, 1);
// 	}
// 	return (digit);
// }
