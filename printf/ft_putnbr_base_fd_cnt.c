/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_cnt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:29:01 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/07 14:11:27 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "ft_printf.h"

static void	ft_number(unsigned long long nb, int length, char *moto)
{
	if (nb >= length)
	{
		ft_number(nb / length, length, moto);
		ft_number(nb % length, length, moto);
	}
	else
		ft_putchar_fd(moto[nb], 1);
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

int	ft_putnbr_base_fdcnt(long long nbr, int digit, char *base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		digit++;
	while (base[len] != '\0')
		len++;
	nbr = flag1((unsigned long long)nbr, len, base);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_number((unsigned long long)nbr, len, base);
	}
	else if (nbr >= 0)
		ft_number(nbr, len, base);
	while (nbr)
	{
		digit++;
		nbr /= len;
	}
	return (digit);
}

int	ft_putnbr_base_fdcnt2(unsigned long long nbr, int digit, char *base)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		digit++;
	while (base[len] != '\0')
		len++;
	nbr = flag1(nbr, len, base);
	ft_number(nbr, len, base);
	while (nbr)
	{
		digit++;
		nbr /= len;
	}
	return (digit);
}