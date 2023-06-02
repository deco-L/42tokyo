/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_cnt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 23:18:04 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libftprintf.h"

static void					ft_number(unsigned long long nb, int length, char *moto);
static unsigned long long	flag1(unsigned long long nbr, int len, char *base);
static unsigned long long	flag2(unsigned long long nbr, int len, char *base);
int							ft_putnbr_base_fdcnt(unsigned long long nbr, int digit, char *base);

static void	ft_number(unsigned long long nb, int length, char *moto)
{
	if (nb >= length)
	{
		ft_number(nb / length, length, moto);
		ft_number(nb % length, length, moto);
	}
	else
	{
		ft_putchar_fd(moto[nb], 1);
	}
	return ;
}

static unsigned long long	flag1(unsigned long long nbr, int len, char *base)
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

static unsigned long long	flag2(unsigned long long nbr, int len, char *base)
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

int	ft_putnbr_base_fdcnt(unsigned long long nbr, int digit, char *base)
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
		ft_number(nbr, len, base);
	}
	else if (nbr > 0)
		ft_number(nbr, len, base);
	while (nbr /= len)
		digit++;
	return (digit);
}

