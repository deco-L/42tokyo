/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:32:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/10 16:34:15 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	char	*c;
// 	unsigned long long d = -2147483646;

// 	c = NULL;
// 	// printf("%u\n", 42967295);
// 	// printf("%llu\n", d);
// 	// printf("%X\n%p\n", 1234, c);
// 	// printf("%p\n", NULL);
// 	// printf("%p\n",c);
// 	// // printf("%p\n", 0);
// 	// c = (char *)malloc(sizeof(char) * 5);
// 	// ft_printf("aaa|%i|aaa%%ccc%Xbbb %s  |%p| %d %c %u %x %X\n", 123, 1234, "abcdef", c, 42, 'c', -1, 1234, 1234);
// 	// ft_printf("%p\n", NULL);
// 	// free(c);
// 	// c = NULL;
// 	// ft_printf("%p\n", c);
// 	// ft_printf("-%d\n-%d\n-|%d|\n", ft_printf(":aaa:"), ft_printf("%x\n", 1234), ft_printf("%pa%%aa%s%d%u%i\n", c, "123", 123, 12, 999));
// 	// c = (char *)malloc(sizeof(char) * 4);
// 	// free(c);
// 	// printf("%d\n", 10);
// 	ft_printf("aa\n");
// 	return (0);
// }

int main(void)
{
	printf("%d\n", 	printf(" [%x] [%X] ", LONG_MAX, LONG_MIN));
	printf("%d\n", ft_printf(" #%x# &%X& ", LONG_MAX, LONG_MIN));
	return (0);
}

// int	main(void)
// {
// 	char	*buf;
// 	buf = "abcd";

// 	printf("|%d|\n", printf("%d\n", -1));
// 	ft_printf("|%d|\n", ft_printf("%d\n", -1));

// 	printf("printf : %c%s%p%d%i%u%x%%\n", 'z', "chiaki", buf, 10, 10, 10, 10);
// 	ft_printf("ft_printf : %c%s%p%d%i%u%x%%\n", 'z', "chiaki", buf, 10, 10, 10, 10);

// 	printf("c : %d, s : %d, p : %d, d : %d, i : %d, u : %d, x : %d, %% : %d\n", printf("a%ca", 'z'), printf("a%sa", "chiaki"), printf("a%pa", buf), printf("a%da", 10), printf("a%ia", 10), printf("a%ua", 10), printf("a%xa", 10), printf("a%%a"));
// 	ft_printf("c : %d, s : %d, p : %d, d : %d, i : %d, u : %d, x : %d, %% : %d\n", ft_printf("a%ca", 'z'), ft_printf("a%sa", "chiaki"), ft_printf("a%pa", buf), ft_printf("a%da", 10), ft_printf("a%ia", 10), ft_printf("a%ua", 10), ft_printf("a%xa", 10), ft_printf("a%%a"));
// 	return (0);
// }

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
