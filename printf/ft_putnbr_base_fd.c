/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/01 14:12:49 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_number(int nb, int length, char *moto, int fd);
static int	flag1(int nbr, int len, char *base);
static int	flag2(int nbr, int len, char *base);
void		ft_putnbr_base_fd(int nbr, char *base, int fd);

static void	ft_number(int nb, int length, char *moto, int fd)
{
	if (nb >= length)
	{
		ft_number(nb / length, length, moto, fd);
		ft_number(nb % length, length, moto, fd);
	}
	else
		ft_putchar_fd(moto[nb], fd);
}

static int	flag1(int nbr, int len, char *base)
{
	int	i;

	i = 0;
	if (len == 0 || len == 1)
	{
		nbr = 0;
		return (nbr);
	}
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
		{
			nbr = 0;
			return (nbr);
		}
		i++;
	}
	return (nbr);
}

static int	flag2(int nbr, int len, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
			{
				nbr = 0;
				return (nbr);
			}
			j++;
		}
		i++;
	}
	return (nbr);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	nbr = flag1(nbr, len, base);
	nbr = flag2(nbr, len, base);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_number(nbr, len, base, fd);
	}
	else if (nbr > 0)
		ft_number(nbr, len, base, fd);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str1[] = "0123456789ABCDEF";
// 	char str2[] = "poneyvif";
// 	char str3[] = "0123456789";
// 	char str4[] = "01";
// 	char str5[] = "";
// 	char str6[] = "-01";
// 	char str7[] = "011";
// 	ft_putnbr_base(255, str1);
// 	puts("");
// 	ft_putnbr_base(255, str2);
// 	puts("");
// 	ft_putnbr_base(255, str3);
// 	puts("");
// 	ft_putnbr_base(42, str4);
// 	puts("");
// 	ft_putnbr_base(255, str5);
// 	puts("");
// 	ft_putnbr_base(255, str6);
// 	puts("");
// 	ft_putnbr_base(255, str7);
// 	puts("");
// 	return (0);
// }