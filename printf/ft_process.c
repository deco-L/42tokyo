/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:44:29 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/03 00:53:39 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libftprintf.h"

void	ft_process_litter(va_list stat, t_check *check);
void	ft_process_point(va_list stat, t_check *check);
void	ft_process_number(va_list stat, t_check *check);
void	ft_process_hexa(va_list stat, t_check *check);

void	ft_process_litter(va_list stat, t_check *check)
{
	char	*buf;

	if (check -> type == PERCENT)
	{
		check -> length = 1;
		ft_putchar_fd('%', 1);
		return ;
	}
	else if (check -> type == CHAR)
	{
		check -> length = 1;
		ft_putchar_fd(va_arg(stat, int), 1);
		return ;
	}
	buf = va_arg(stat, char *);
	check -> length = ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	return ;
}

void	ft_process_point(va_list stat, t_check *check)
{
	unsigned long long	p;

	p = va_arg(stat, unsigned long long);
	if (p == 0)
	{
		check -> length = 5;
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	check -> length = 2;
	check -> length += ft_putnbr_base_fdcnt(p, 1, "0123456789abcdef");
	return ;
}

void	ft_process_number(va_list stat, t_check *check)
{
	int				nbr;
	unsigned int	unnbr;

	if (check -> type == DECIMAL || check -> type == INTEJER)
	{
		nbr = va_arg(stat, int);
		check -> length = ft_putnbr_base_fdcnt(nbr, 1, "0123456789");
		return ;
	}
	unnbr = (unsigned int)va_arg(stat, int);
	check -> length = ft_putnbr_base_fdcnt(unnbr, 1, "0123456789");
	return ;
}

void	ft_process_hexa(va_list stat, t_check *check)
{
	unsigned long long	hexalow;
	unsigned long long	hexaupp;

	if (check -> type == HEXALOW)
	{
		hexalow = va_arg(stat, unsigned long long);
		check -> length = ft_putnbr_base_fdcnt(hexalow, 1, "0123456789abcdef");
		return ;
	}
	hexaupp = va_arg(stat, unsigned long long);
	check -> length = ft_putnbr_base_fdcnt(hexaupp, 1, "0123456789ABCDEF");
	return ;
}
