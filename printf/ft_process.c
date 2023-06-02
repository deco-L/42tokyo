/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:44:29 by csakamot          #+#    #+#             */
/*   Updated: 2023/06/02 17:15:10 by csakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "libftprintf.h"

void	ft_process_litter(va_list stat, t_check *check);
void	ft_process_point(va_list stat, t_check *check);
void	ft_process_number(va_list stat, t_check *check);
void	ft_process_hexa(va_list stat, t_check *check);
int		ft_putnbr_fd_cnt(int n, int digit, int fd);

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
	free(buf);
	return ;
}

void	ft_process_point(va_list stat, t_check *check)
{
	unsigned long long	p;

	p = va_arg(stat, unsigned long long);
	if (p == 0)
	{
		check -> length = 3;
		ft_putstr_fd("0x0", 1);
		return ;
	}
	check -> length = 14;
	ft_putnbr_base_fdcnt(p, 0, "0123456789abcdef");
	return ;
}

void	ft_process_number(va_list stat, t_check *check)
{
	int				nbr;
	unsigned int	unnbr;

	if (check -> type == DECIMAL || check -> type == INTEJER)
	{
		nbr = va_arg(stat, int);
		check -> length = ft_putnbr_fd_cnt(nbr, 0, 1);
		return ;
	}
	unnbr = (unsigned int)va_arg(stat, int);
	check -> length = ft_putnbr_base_fdcnt(unnbr, 0, "0123456789abcdef");
	return ;
}

void	ft_process_hexa(va_list stat, t_check *check)
{
	unsigned long long	hexalow;
	unsigned long long	hexaupp;

	if (check -> type == HEXALOW)
	{
		hexalow = va_arg(stat, unsigned long long);
		check -> length = ft_putnbr_base_fdcnt(hexalow, 0, "0123456789abcdef");
		return ;
	}
	hexaupp = va_arg(stat, unsigned long long);
	check -> length = ft_putnbr_base_fdcnt(hexaupp, 0, "0123456789ABCDEF");
	return ;
}

int	ft_putnbr_fd_cnt(int n, int digit, int fd)
{
	long long	nbr;

	nbr = (long long) n;
	if (n < 0)
	{
		digit++;
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		digit++;
		nbr += '0';
		write(fd, &nbr, 1);
	}
	return (digit);
}
