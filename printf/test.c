/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:32:37 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 20:34:06 by csakamot         ###   ########.fr       */
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
	// printf("%X\n%p\n", 1234, c);
	ft_printf("aaa|%i|aaa%%ccc%Xbbb  |%p|\n", 123, 1234, c);
	ft_printf("%d\n", ft_printf(":aaa:"));
	return (0);
}
